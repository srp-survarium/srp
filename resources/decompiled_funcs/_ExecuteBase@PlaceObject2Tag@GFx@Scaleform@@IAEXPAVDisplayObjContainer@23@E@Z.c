void __thiscall Scaleform::GFx::PlaceObject2Tag::ExecuteBase(
        Scaleform::GFx::PlaceObject2Tag *this,
        Scaleform::GFx::DisplayObjContainer *m,
        int version)
{
  Scaleform::GFx::ASStringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  char v7; // bl
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringManager *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // esi
  char v12; // bl
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // [esp+1ECh] [ebp-7Ch] BYREF
  Scaleform::GFx::ASStringNode *v15; // [esp+1F0h] [ebp-78h] BYREF
  _BYTE v16[4]; // [esp+1F4h] [ebp-74h] BYREF
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData data; // [esp+1F8h] [ebp-70h] BYREF

  v15 = 0;
  Scaleform::Render::Cxform::Cxform(&data.Pos.ColorTransform);
  data.Pos.Matrix_1.M[0][0] = 1.0;
  data.Pos.Matrix_1.M[0][1] = 0.0;
  data.Pos.Matrix_1.M[0][2] = 0.0;
  data.Pos.Matrix_1.M[0][3] = 0.0;
  data.Pos.Matrix_1.M[1][0] = 0.0;
  data.Pos.Matrix_1.M[1][2] = 0.0;
  data.Pos.Matrix_1.M[1][3] = 0.0;
  data.Pos.Matrix_1.M[1][1] = 1.0;
  data.Pos.pFilters.pObject = 0;
  data.Pos.CharacterId.Id = 0x40000;
  data.Pos.Depth = 0;
  data.Pos.Ratio = 0.0;
  memset(&data.Pos.ClassName, 0, 9);
  Scaleform::GFx::PlaceObject2Tag::UnpackBase(this, &data, version);
  if ( data.PlaceType )
  {
    if ( data.PlaceType == Place_Move )
    {
      Scaleform::GFx::DisplayObjContainer::MoveDisplayObject(m, &data.Pos);
      goto LABEL_27;
    }
    if ( data.PlaceType != Place_Replace )
      goto LABEL_27;
    StringManager = Scaleform::GFx::InteractiveObject::GetStringManager(m);
    if ( data.Name )
    {
      v7 = 8;
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager, (char *)data.Name);
      ++StringNode->RefCount;
      v14 = StringNode;
      p_EmptyStringNode = StringNode;
    }
    else
    {
      ++StringManager->EmptyStringNode.RefCount;
      p_EmptyStringNode = &StringManager->EmptyStringNode;
      v14 = &StringManager->EmptyStringNode;
      StringNode = &StringManager->EmptyStringNode;
      v7 = 4;
    }
    v15 = v14;
    ++v14->RefCount;
    if ( (v7 & 8) != 0 )
    {
      v7 &= ~8u;
      v8 = StringNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    }
    if ( (v7 & 4) != 0 )
    {
      v8 = p_EmptyStringNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
    }
    m->CreateAndReplaceDisplayObject(
      m,
      (const Scaleform::GFx::CharPosInfo *)&data,
      (const Scaleform::GFx::ASString *)&v15,
      (Scaleform::GFx::DisplayObjectBase **)v16);
    v9 = v15;
  }
  else
  {
    v10 = Scaleform::GFx::InteractiveObject::GetStringManager(m);
    if ( data.Name )
    {
      v12 = 2;
      v13 = Scaleform::GFx::ASStringManager::CreateStringNode(v10, (char *)data.Name);
      ++v13->RefCount;
      v15 = v13;
      v11 = v13;
    }
    else
    {
      v11 = &v10->EmptyStringNode;
      v12 = 1;
      ++v10->EmptyStringNode.RefCount;
      v15 = &v10->EmptyStringNode;
      v13 = &v10->EmptyStringNode;
    }
    v14 = v15;
    ++v15->RefCount;
    if ( (v12 & 2) != 0 )
    {
      v12 &= ~2u;
      v8 = v13->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
    if ( (v12 & 1) != 0 )
    {
      v8 = v11->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
    m->AddDisplayObject(
      m,
      (const Scaleform::GFx::CharPosInfo *)&data,
      (const Scaleform::GFx::ASString *)&v14,
      data.pEventHandlers,
      0,
      -1u,
      4u,
      0,
      0);
    v9 = v14;
  }
  if ( !--v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
LABEL_27:
  if ( data.Pos.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)data.Pos.pFilters.pObject);
}
