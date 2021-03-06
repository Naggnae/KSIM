// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TriangulatorBPLibrary.h"
#include "Triangulator.h"
#include "earcut.hpp"
#include <array>
#include <vector>

UTriangulatorBPLibrary::UTriangulatorBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

TArray<int> UTriangulatorBPLibrary::TriangulatorSampleFunction(const TArray<FPolyline>& polylines)
{
	using namespace std;
	using Coord = double;
	using Point = array<Coord, 2>;
	vector<vector<Point>> polygon;
	for (auto& polyline : polylines)
	{
		vector<Point> points;
		for (auto& vec : polyline.Points) {
			points.push_back({ vec.X , vec.Y });
		}
		polygon.push_back(points);
	}
	vector<int> indices = mapbox::earcut<int>(polygon);
	TArray<int> result;
	for (int i : indices) {
		result.Add(i);
	}
	return result;
}

