// Fill out your copyright notice in the Description page of Project Settings.

#include "XMLParserSS.h"
#include "locale"

void UXMLParserSS::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Error, TEXT("Init XML Parser Subsystem"));
}

void UXMLParserSS::InitXMLData(FString XMLFileName, TArray<FString>& LevelNameList)
{
	tinyxml2::XMLElement* LevelNode;

	setlocale(LC_ALL, ""); // Enable Korean file path 
	
	char* FilePath = TCHAR_TO_UTF8(*FString(FPaths::ProjectContentDir()+"XML_File/"+XMLFileName));
	//tinyxml2::XMLError Error_Load = XML_FILE.LoadFile(TCHAR_TO_ANSI(*fstr_xml_file_path));

	tinyxml2::XMLError LoadError = XMLFile.LoadFile(FilePath);

	if (LoadError == 0)
	{
		LevelNode = XMLFile.RootElement()->FirstChildElement("Levels")->FirstChildElement("Level");

		LevelNodeList.Empty();
		for (tinyxml2::XMLElement* ele = LevelNode; ele != NULL; ele = ele->NextSiblingElement())
		{
			LevelNodeList.Add(ele);
			LevelNameList.Add(UTF8_TO_TCHAR(ele->FirstChildElement("Name")->GetText()));
		}
		LevelNameList.Sort();
		UE_LOG(LogTemp, Error, TEXT("XML file load sucess!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("XML file load fail!"));
		//UE_LOG(LogTemp, Error, TEXT("%s"),*fstr_xml_file_path);
	}
}

void UXMLParserSS::SetMeshDataList(FString LevelName)
{
	UGI* GI = Cast<UGI>(GetGameInstance());

	for (tinyxml2::XMLElement* ele : LevelNodeList)
	{
		if (LevelName == UTF8_TO_TCHAR(ele->FirstChildElement("Name")->GetText()))
		{
			GI->WallMeshDataList = SetWallMeshData(ele);
			GI->ColumnMeshDataList = SetColumnMeshData(ele);
			GI->FloorMeshDataList = SetFloorMeshData(ele);
			GI->ObjectMeshDataList = SetObjectMeshData(ele);
			GI->NodeDataList = SetNodeData(ele);
			//StairMesh = SetStairMesh(ele);
		}
	}
}

TArray<FWallMeshData> UXMLParserSS::SetWallMeshData(tinyxml2::XMLElement* LevelNode)
{
	FWallMeshData WallMeshData;

	TArray<FWallMeshData> WallMeshDataList;

	tinyxml2::XMLElement* WallMeshNode = LevelNode->FirstChildElement("Mesh");
	tinyxml2::XMLElement* CurtainMeshNode = WallMeshNode->NextSiblingElement();

	TArray<FString> PolygonList;
	TArray<FString> VertexXYZList;

	TArray<FString> TriangleList;
	TArray<FString> IndexList;

	// Basic wall
	WallMeshData.Type = UTF8_TO_TCHAR(WallMeshNode->Attribute("Type"));
	
	FString(WallMeshNode->FirstChildElement("Vertex")->GetText()).ParseIntoArray(PolygonList,TEXT(","),false);
	
	for (auto& Polygon: PolygonList )
	{
		Polygon.ParseIntoArray(VertexXYZList, TEXT(" "), false);
		WallMeshData.VertexList.Add(FVector(-FCString::Atof(*VertexXYZList[0].TrimQuotes()),FCString::Atof(*VertexXYZList[2].TrimQuotes()),FCString::Atof(*VertexXYZList[1].TrimQuotes())));
	}
	
	FString(WallMeshNode->FirstChildElement("Face")->GetText()).ParseIntoArray(TriangleList, TEXT(","),false);
	for (auto& Face : TriangleList)
	{
		Face.ParseIntoArray(IndexList, TEXT(" "),false);
		
		for (auto& Index  : IndexList)
		{
			WallMeshData.TriangleIndexList.Add(FCString::Atoi(*Index.TrimQuotes()));
		}
	}
	Algo::Reverse(WallMeshData.TriangleIndexList);

	WallMeshDataList.Add(WallMeshData);

	// Init array
	PolygonList.Empty();
	VertexXYZList.Empty();
	TriangleList.Empty();
	IndexList.Empty();

	WallMeshData.VertexList.Empty();
	WallMeshData.TriangleIndexList.Empty();
	
	// Curtain wall
	WallMeshData.Type = UTF8_TO_TCHAR(CurtainMeshNode->Attribute("Type"));
	
	FString(CurtainMeshNode->FirstChildElement("Vertex")->GetText()).ParseIntoArray(PolygonList,TEXT(","),false);
	
	for (auto& Polygon: PolygonList )
	{
		Polygon.ParseIntoArray(VertexXYZList, TEXT(" "), false);
		WallMeshData.VertexList.Add(FVector(-FCString::Atof(*VertexXYZList[0].TrimQuotes()),FCString::Atof(*VertexXYZList[2].TrimQuotes()),FCString::Atof(*VertexXYZList[1].TrimQuotes())));
	}
	
	FString(CurtainMeshNode->FirstChildElement("Face")->GetText()).ParseIntoArray(TriangleList, TEXT(","),false);
	
	for (auto& Face : TriangleList)
	{
		Face.ParseIntoArray(IndexList, TEXT(" "),false);
		
		for (auto& Index : IndexList)
		{
			WallMeshData.TriangleIndexList.Add(FCString::Atoi(*Index.TrimQuotes()));
		}
	}
	Algo::Reverse(WallMeshData.TriangleIndexList);

	WallMeshDataList.Add(WallMeshData);
	
	return WallMeshDataList;
}

TArray<FColumnMeshData> UXMLParserSS::SetColumnMeshData(tinyxml2::XMLElement* LevelNode)
{
	tinyxml2::XMLElement* ColumnNode = LevelNode->FirstChildElement("ElementCollection")->FirstChildElement("Column");

	float Elevation = atof(LevelNode->FirstChildElement("Elevation")->GetText());
	float Height = atof(LevelNode->FirstChildElement("Height")->GetText());
	float Radius;

	FColumnMeshData ColumnMeshData;

	TArray<FColumnMeshData> ColumnMeshDataList;

	FString PointX;
	FString PointY;

	FVector CircleStart;
	FVector CircleEnd;
	
	for (tinyxml2::XMLElement* ele = ColumnNode; ele != NULL; ele = ele->NextSiblingElement())
	{
		if (FString("Rect") == UTF8_TO_TCHAR(ele->FirstChildElement()->NextSiblingElement()->Name()))
		{
			ColumnMeshData.VertexList.Empty();
		
			ColumnMeshData.Shape = "Rectangle";
			
			for (tinyxml2::XMLElement* ele2 = ele->FirstChildElement()->NextSiblingElement()->FirstChildElement(); ele2 != NULL; ele2 = ele2->NextSiblingElement())
			{
				FString(ele2->FirstChildElement("Point")->FirstChildElement("Pos")->GetText()).Split(TEXT(","), &PointX, &PointY);

				ColumnMeshData.VertexList.Add(FVector(-FCString::Atof(*PointX.TrimQuotes()), -FCString::Atof(*PointY.TrimQuotes()), Elevation));
				
			}

			for (int i = 0; i < 4; i++)
			{
				ColumnMeshData.VertexList.Add(FVector(ColumnMeshData.VertexList[i].X, ColumnMeshData.VertexList[i].Y, Elevation + Height));
			}
			
			ColumnMeshDataList.Add(ColumnMeshData);
		}		
		else if (FString("Circle") == UTF8_TO_TCHAR(ele->FirstChildElement()->NextSiblingElement()->Name()))
		{
			ColumnMeshData.VertexList.Empty();
			
			ColumnMeshData.Shape = "Circle";

			for (tinyxml2::XMLElement* ele2 =  ele->FirstChildElement()->NextSiblingElement(); ele2 != NULL; ele2 = ele2->NextSiblingElement())
			{
				FString(ele2->FirstChildElement("Center")->FirstChildElement("Point")->FirstChildElement("Pos")->GetText()).Split(TEXT(","), &PointX,&PointY);
				
				CircleStart.Set(-FCString::Atof(*PointX.TrimQuotes()),-FCString::Atof(*PointY.TrimQuotes()),Elevation);
				CircleEnd.Set(-FCString::Atof(*PointX.TrimQuotes()),-FCString::Atof(*PointY.TrimQuotes()),Elevation + Height);

				Radius = FCString::Atof(UTF8_TO_TCHAR(ele2->FirstChildElement("Radius")->GetText()));

				ColumnMeshData.VertexList = SetCircleColumnVector(CircleStart, CircleEnd, Radius, 20);
				
				ColumnMeshDataList.Add(ColumnMeshData);
			}
		}
	}
	return ColumnMeshDataList;
}

TArray<FFloorMeshData> UXMLParserSS::SetFloorMeshData(tinyxml2::XMLElement* LevelNode)
{
	float Elevation = atof(LevelNode->FirstChildElement("Elevation")->GetText());

	tinyxml2::XMLElement* SpaceNode = LevelNode->FirstChildElement("ElementCollection")->FirstChildElement("Space");
	tinyxml2::XMLElement* BoundaryNode;

	TArray<FVector> VertexList;
	
	FString PointX, PointY;

	FFloorMeshData FloorMeshData;

	TArray<FFloorMeshData> FloorMeshDataList;
	
	if (SpaceNode != NULL)
	{
		for (tinyxml2::XMLElement* ele = SpaceNode; ele != NULL; ele = ele->NextSiblingElement("Space"))
		{
			VertexList.Empty();
			
			BoundaryNode = ele->FirstChildElement("Boundary");

			// Set Space's floor vector
			for (tinyxml2::XMLElement* ele2 = BoundaryNode->FirstChildElement("Line"); ele2 != NULL; ele2 = ele2->NextSiblingElement())
			{
				for (tinyxml2::XMLElement* ele3 = ele2->FirstChildElement("Pos"); ele3 != NULL; ele3 = ele3->NextSiblingElement())
				{
					FString(ele3->GetText()).Split(TEXT(","), &PointX, &PointY);

					VertexList.AddUnique(FVector(-FCString::Atof(*PointX.TrimQuotes()),FCString::Atof(*PointY.TrimQuotes()),Elevation));
				}
			}
			FloorMeshData.SpaceName = UTF8_TO_TCHAR(ele->Attribute("name"));
			FloorMeshData.VertexList = VertexList;
				 
			FloorMeshDataList.Add(FloorMeshData);
		}
	}
	return FloorMeshDataList;
}

TArray<F3DObjectData> UXMLParserSS::SetObjectMeshData(tinyxml2::XMLElement* LevelNode)
{
	float Elevation = atof(LevelNode->FirstChildElement("Elevation")->GetText());
	float Scale, Rotation;
	tinyxml2::XMLElement* MassNode = LevelNode->FirstChildElement("ElementCollection")->FirstChildElement("Mass");
	
	TArray<F3DObjectData> ObjectDataList;
	
	F3DObjectData ObjectData;

	FString PointX, PointY;
	
	TArray<FString> PolygonList, VertexXYZList;

	TArray<FString> TriangleList, IndexList;

	if (MassNode != NULL)
	{		
		for (tinyxml2::XMLElement* ele = MassNode; ele != NULL; ele = ele->NextSiblingElement("Mass"))
		{
			ObjectData.Name = UTF8_TO_TCHAR(ele->FirstChildElement("Name")->GetText());
			
			Scale = atof(ele->FirstChildElement("Scale")->GetText());
			Rotation = atof(ele->FirstChildElement("Rotation")->GetText());
			ObjectData.Scale = FVector(Scale, Scale, Scale);
			ObjectData.Rotation = FRotator(Rotation,0,0);

			FString(ele->FirstChildElement("Point")->FirstChildElement("Pos")->GetText()).Split(TEXT(","),&PointX, &PointY);
			
			ObjectData.Location = FVector(-FCString::Atof(*PointX.TrimQuotes()), Elevation,-FCString::Atof(*PointY.TrimQuotes()));
			
			FString(ele->FirstChildElement("Mesh")->FirstChildElement("Vertex")->GetText()).ParseIntoArray(PolygonList, TEXT(","), false);

			for (int i = 0; i < PolygonList.Num(); i++)
			{
				PolygonList[i].ParseIntoArray(VertexXYZList,TEXT(" "), false);
				ObjectData.VertexList.Add(FVector(-FCString::Atof(*VertexXYZList[0].TrimQuotes()),-FCString::Atof(*VertexXYZList[2].TrimQuotes()),FCString::Atof(*VertexXYZList[1].TrimQuotes())));
			}

			FString(ele->FirstChildElement("Mesh")->FirstChildElement("Face")->GetText()).ParseIntoArray(TriangleList, TEXT(","), false);

			for (int i = 0; i < TriangleList.Num(); i++)
			{
				TriangleList[i].ParseIntoArray(IndexList,TEXT(" "), false);

				ObjectData.TriangleIndexList.Add(FCString::Atoi(*IndexList[2].TrimQuotes()));
				ObjectData.TriangleIndexList.Add(FCString::Atoi(*IndexList[0].TrimQuotes()));
				ObjectData.TriangleIndexList.Add(FCString::Atoi(*IndexList[1].TrimQuotes()));
			
			}
			ObjectDataList.Add(ObjectData);
		}
	}	
	return ObjectDataList;
}


TArray<FNodeData> UXMLParserSS::SetNodeData(tinyxml2::XMLElement* LevelNode)
{
	float Elevation = atof(LevelNode->FirstChildElement("Elevation")->GetText());
	float Height = atof(LevelNode->FirstChildElement("Height")->GetText());

	TArray<FNodeData> NodeDataList;
	FNodeData NodeData;

	FString PointX, PointY;
	
	tinyxml2::XMLElement* NodeNode = LevelNode->FirstChildElement("ElementCollection")->FirstChildElement("Topology")->FirstChildElement("Node");
	tinyxml2::XMLElement* TopologyPropertyNode;
	tinyxml2::XMLElement* PropertyNode;
	tinyxml2::XMLElement* TargetNode;
	
	for (tinyxml2::XMLElement* ele = NodeNode; ele != NULL; ele = ele->NextSiblingElement("Node"))
	{
		NodeData.ID = UTF8_TO_TCHAR(ele->Attribute("id"));

		TopologyPropertyNode = ele->FirstChildElement("TopologyNodeProperties");
		
		for(tinyxml2::XMLElement* ele2 =TopologyPropertyNode; ele2 != NULL; ele2 = ele2->NextSiblingElement("TopologyNodePropertyNode"))
		{
			PropertyNode = ele2->FirstChildElement("Property");

			NodeData.Name = UTF8_TO_TCHAR(PropertyNode->FirstChildElement("Value")->GetText());
			PropertyNode = PropertyNode->NextSiblingElement("Property");

			NodeData.Type = atoi(PropertyNode->FirstChildElement("Value")->GetText());
			PropertyNode = PropertyNode->NextSiblingElement("Property");

			NodeData.OwnerType = UTF8_TO_TCHAR(PropertyNode->FirstChildElement("Value")->GetText());
			PropertyNode = PropertyNode->NextSiblingElement("Property");

			NodeData.OwnerID = UTF8_TO_TCHAR(PropertyNode->FirstChildElement("Value")->GetText());
			PropertyNode = PropertyNode->NextSiblingElement("Property");

			if (UTF8_TO_TCHAR(PropertyNode->FirstChildElement("Value")->GetText()) == FString("True"))
			{
				NodeData.isPassable = true;
			}
			else
			{
				NodeData.isPassable = false;
			}
			PropertyNode = PropertyNode->NextSiblingElement("Property");
			
			if (UTF8_TO_TCHAR(PropertyNode->FirstChildElement("Value")->GetText()) == FString("True"))
			{
				NodeData.isExit = true;
			}
			else
			{
				NodeData.isExit = false;
			}
			PropertyNode = PropertyNode->NextSiblingElement("Property");

			if (PropertyNode != NULL)
			{
				NodeData.DoorWidth = atof(PropertyNode->FirstChildElement("Value")->GetText());
			}
		}

		FString(TopologyPropertyNode->NextSiblingElement("Point")->FirstChildElement("Pos")->GetText()).Split(TEXT(","), &PointX,&PointY);

		NodeData.Location = FVector(-FCString::Atof(*PointX.TrimQuotes()), FCString::Atof(*PointY.TrimQuotes()), Elevation+Height/3);

		TargetNode = TopologyPropertyNode->NextSiblingElement("Target");

		NodeData.TargetIDs.Empty();
		for (tinyxml2::XMLElement* ele2 = TargetNode; ele2 != NULL; ele2 = ele2->NextSiblingElement("Target"))
		{
			NodeData.TargetIDs.Add(UTF8_TO_TCHAR(ele2->Attribute("id")));
		}
		
		NodeDataList.Add(NodeData);
	}

	return NodeDataList;
}

TArray<FVector> UXMLParserSS::SetCircleColumnVector(FVector StartPoint, FVector EndPoint, float Radius, int32 Segments)
{
	TArray<FVector> ColumnVertexList;
	
	Segments = FMath::Max(Segments, 4);

	// Rotate a point around axis to form cylinder segments
	FVector Segment;
	FVector P1, P2, P3, P4;
	
	const float AngleInc = 360.f / Segments;
	float Angle = AngleInc;

	// Default for Axis is up
	FVector Axis = (EndPoint - StartPoint).GetSafeNormal();
	if( Axis.IsZero() )
	{
		Axis = FVector(0.f, 0.f, 1.f);
	}

	FVector Perpendicular;
	FVector Dummy;

	Axis.FindBestAxisVectors(Perpendicular, Dummy);
		
	Segment = Perpendicular.RotateAngleAxis(0, Axis) * Radius;
	P1 = Segment + StartPoint;
	P3 = Segment + EndPoint;

	while( Segments-- )
	{
		Segment = Perpendicular.RotateAngleAxis(Angle, Axis) * Radius;
		P2 = Segment + StartPoint;
		P4 = Segment + EndPoint;

		P1 = P2;
		P3 = P4;

		ColumnVertexList.Add(P1);
		ColumnVertexList.Add(P3);
				
		Angle += AngleInc;
	}
	return ColumnVertexList;
}

