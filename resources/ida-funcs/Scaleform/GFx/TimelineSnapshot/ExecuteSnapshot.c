void __thiscall Scaleform::GFx::TimelineSnapshot::ExecuteSnapshot(
        Scaleform::GFx::TimelineSnapshot *this,
        Scaleform::GFx::DisplayObjContainer *pdispObj)
{
  int v2; // ebx
  Scaleform::GFx::TimelineSnapshot::SnapshotElement *i; // edi
  Scaleform::GFx::ASStringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *v5; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // edx
  int *v7; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  bool v9; // zf
  unsigned int v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringManager *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // ecx
  Scaleform::GFx::ASStringNode *v14; // edx
  int *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  int v17; // [esp+0h] [ebp-B0h]
  int v18; // [esp+4h] [ebp-ACh]
  int v19; // [esp+8h] [ebp-A8h]
  int v20; // [esp+Ch] [ebp-A4h]
  int v21; // [esp+10h] [ebp-A0h]
  Scaleform::GFx::ASStringNode *v22; // [esp+14h] [ebp-9Ch] BYREF
  Scaleform::GFx::ASStringNode *v23; // [esp+18h] [ebp-98h] BYREF
  Scaleform::GFx::ASStringNode *v24; // [esp+1Ch] [ebp-94h] BYREF
  Scaleform::GFx::ASStringNode *v25; // [esp+20h] [ebp-90h] BYREF
  Scaleform::List<Scaleform::GFx::TimelineSnapshot::SnapshotElement,Scaleform::GFx::TimelineSnapshot::SnapshotElement> *p_SnapshotList; // [esp+24h] [ebp-8Ch]
  Scaleform::GFx::ASStringNode *v27; // [esp+28h] [ebp-88h] BYREF
  Scaleform::GFx::ASStringNode *v28; // [esp+2Ch] [ebp-84h] BYREF
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData v29; // [esp+30h] [ebp-80h] BYREF
  _BYTE v30[4]; // [esp+ACh] [ebp-4h] BYREF

  v2 = 0;
  p_SnapshotList = &this->SnapshotList;
  if ( (Scaleform::List<Scaleform::GFx::TimelineSnapshot::SnapshotElement,Scaleform::GFx::TimelineSnapshot::SnapshotElement> *)this->SnapshotList.Root.pNext != &this->SnapshotList )
  {
    for ( i = this->SnapshotList.Root.pNext; ; i = i->pNext )
    {
      switch ( i->PlaceType )
      {
        case 0u:
          Scaleform::Render::Cxform::Cxform(&v29.Pos.ColorTransform);
          v29.Pos.Matrix_1.M[0][0] = 1.0;
          v29.Pos.Matrix_1.M[0][1] = 0.0;
          v29.Pos.pFilters.pObject = 0;
          v29.Pos.Matrix_1.M[0][2] = 0.0;
          v29.Pos.Depth = 0;
          v29.Pos.Matrix_1.M[0][3] = 0.0;
          memset(&v29.Pos.ClassName, 0, 9);
          v29.Pos.Matrix_1.M[1][0] = 0.0;
          v29.Pos.Matrix_1.M[1][2] = 0.0;
          v29.Pos.Matrix_1.M[1][3] = 0.0;
          v29.Pos.Matrix_1.M[1][1] = 1.0;
          v29.Pos.CharacterId.Id = 0x40000;
          v29.Pos.Ratio = 0.0;
          Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(
            &i->Tags,
            &v29,
            v17,
            v18,
            v19,
            v20,
            v21,
            (int)v22,
            (int)v23,
            (int)v24,
            (int)v25,
            (int)p_SnapshotList,
            (int)v27,
            (int)v28,
            SLODWORD(v29.Pos.ColorTransform.M[0][0]),
            SLOBYTE(v29.Pos.ColorTransform.M[0][1]));
          StringManager = Scaleform::GFx::InteractiveObject::GetStringManager(pdispObj);
          if ( v29.Name )
          {
            v2 |= 2u;
            StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager, (__m128i *)v29.Name);
            p_EmptyStringNode = v22;
            v5 = StringNode;
            ++StringNode->RefCount;
            v27 = StringNode;
            v7 = (int *)&v27;
          }
          else
          {
            v5 = v27;
            p_EmptyStringNode = &StringManager->EmptyStringNode;
            v2 |= 1u;
            ++StringManager->EmptyStringNode.RefCount;
            v22 = &StringManager->EmptyStringNode;
            v7 = (int *)&v22;
          }
          v28 = (Scaleform::GFx::ASStringNode *)*v7;
          ++v28->RefCount;
          if ( (v2 & 2) != 0 )
          {
            v2 &= ~2u;
            v9 = v5->RefCount-- == 1;
            if ( v9 )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v5);
              p_EmptyStringNode = v22;
            }
          }
          if ( (v2 & 1) != 0 )
          {
            v2 &= ~1u;
            v9 = p_EmptyStringNode->RefCount-- == 1;
            if ( v9 )
              Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
          }
          v10 = 4;
          if ( (i->Flags & 2) != 0 )
            v10 = 6;
          pdispObj->AddDisplayObject(
            pdispObj,
            (const Scaleform::GFx::CharPosInfo *)&v29,
            (const Scaleform::GFx::ASString *)&v28,
            v29.pEventHandlers,
            0,
            i->CreateFrame,
            v10,
            0,
            0);
          v11 = v28;
          goto LABEL_16;
        case 1u:
          Scaleform::Render::Cxform::Cxform(&v29.Pos.ColorTransform);
          v29.Pos.Matrix_1.M[0][0] = 1.0;
          v29.Pos.Matrix_1.M[0][1] = 0.0;
          v29.Pos.pFilters.pObject = 0;
          v29.Pos.Matrix_1.M[0][2] = 0.0;
          v29.Pos.Depth = 0;
          v29.Pos.Matrix_1.M[0][3] = 0.0;
          memset(&v29.Pos.ClassName, 0, 9);
          v29.Pos.Matrix_1.M[1][0] = 0.0;
          v29.Pos.Matrix_1.M[1][2] = 0.0;
          v29.Pos.Matrix_1.M[1][3] = 0.0;
          v29.Pos.Matrix_1.M[1][1] = 1.0;
          v29.Pos.CharacterId.Id = 0x40000;
          v29.Pos.Ratio = 0.0;
          Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(
            &i->Tags,
            &v29,
            v17,
            v18,
            v19,
            v20,
            v21,
            (int)v22,
            (int)v23,
            (int)v24,
            (int)v25,
            (int)p_SnapshotList,
            (int)v27,
            (int)v28,
            SLODWORD(v29.Pos.ColorTransform.M[0][0]),
            SLOBYTE(v29.Pos.ColorTransform.M[0][1]));
          Scaleform::GFx::DisplayObjContainer::MoveDisplayObject(pdispObj, &v29.Pos);
          goto LABEL_18;
        case 2u:
          Scaleform::Render::Cxform::Cxform(&v29.Pos.ColorTransform);
          v29.Pos.Matrix_1.M[0][0] = 1.0;
          v29.Pos.Matrix_1.M[0][1] = 0.0;
          v29.Pos.Matrix_1.M[0][2] = 0.0;
          v29.Pos.Matrix_1.M[0][3] = 0.0;
          v29.Pos.Matrix_1.M[1][0] = 0.0;
          v29.Pos.Matrix_1.M[1][2] = 0.0;
          v29.Pos.Matrix_1.M[1][3] = 0.0;
          v29.Pos.Matrix_1.M[1][1] = 1.0;
          v29.Pos.pFilters.pObject = 0;
          v29.Pos.CharacterId.Id = 0x40000;
          v29.Pos.Depth = 0;
          memset(&v29.Pos.ClassName, 0, 9);
          v29.Pos.Ratio = 0.0;
          Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(
            &i->Tags,
            &v29,
            v17,
            v18,
            v19,
            v20,
            v21,
            (int)v22,
            (int)v23,
            (int)v24,
            (int)v25,
            (int)p_SnapshotList,
            (int)v27,
            (int)v28,
            SLODWORD(v29.Pos.ColorTransform.M[0][0]),
            SLOBYTE(v29.Pos.ColorTransform.M[0][1]));
          v12 = Scaleform::GFx::InteractiveObject::GetStringManager(pdispObj);
          if ( v29.Name )
          {
            v2 |= 8u;
            v16 = Scaleform::GFx::ASStringManager::CreateStringNode(v12, (__m128i *)v29.Name);
            v14 = v23;
            v13 = v16;
            ++v16->RefCount;
            v24 = v16;
            v15 = (int *)&v24;
          }
          else
          {
            v13 = v24;
            v14 = &v12->EmptyStringNode;
            v2 |= 4u;
            ++v12->EmptyStringNode.RefCount;
            v23 = &v12->EmptyStringNode;
            v15 = (int *)&v23;
          }
          v25 = (Scaleform::GFx::ASStringNode *)*v15;
          ++v25->RefCount;
          if ( (v2 & 8) != 0 )
          {
            v2 &= ~8u;
            v9 = v13->RefCount-- == 1;
            if ( v9 )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v13);
              v14 = v23;
            }
          }
          if ( (v2 & 4) != 0 )
          {
            v2 &= ~4u;
            v9 = v14->RefCount-- == 1;
            if ( v9 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v14);
          }
          pdispObj->CreateAndReplaceDisplayObject(
            pdispObj,
            (const Scaleform::GFx::CharPosInfo *)&v29,
            (const Scaleform::GFx::ASString *)&v25,
            (Scaleform::GFx::DisplayObjectBase **)v30);
          v11 = v25;
LABEL_16:
          if ( !--v11->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
LABEL_18:
          if ( v29.Pos.pFilters.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v29.Pos.pFilters.pObject);
          break;
        case 3u:
          Scaleform::GFx::DisplayObjContainer::RemoveDisplayObject(
            pdispObj,
            i->Depth,
            (Scaleform::GFx::ResourceId)0x40000);
          break;
        default:
          break;
      }
      if ( i == p_SnapshotList->Root.pPrev )
        break;
    }
  }
}
