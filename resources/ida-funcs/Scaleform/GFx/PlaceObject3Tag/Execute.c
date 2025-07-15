void __thiscall Scaleform::GFx::PlaceObject3Tag::Execute(
        Scaleform::GFx::PlaceObject3Tag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::PlaceObject3Tag_vtbl *v3; // edx
  void (__thiscall *Unpack)(Scaleform::GFx::GFxPlaceObjectBase *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *); // edx
  Scaleform::GFx::ASStringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  char v8; // bl
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringManager *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // esi
  char v13; // bl
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // [esp+24h] [ebp-7Ch] BYREF
  Scaleform::GFx::ASStringNode *v16; // [esp+28h] [ebp-78h] BYREF
  _BYTE v17[4]; // [esp+2Ch] [ebp-74h] BYREF
  Scaleform::GFx::CharPosInfo v18; // [esp+30h] [ebp-70h] BYREF
  const Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v19; // [esp+90h] [ebp-10h]
  __m128i *v20; // [esp+94h] [ebp-Ch]
  int v21; // [esp+98h] [ebp-8h]

  v16 = 0;
  Scaleform::Render::Cxform::Cxform(&v18.ColorTransform);
  v3 = this->__vftable;
  v18.Matrix_1.M[0][0] = 1.0;
  Unpack = v3->Unpack;
  v18.Matrix_1.M[0][1] = 0.0;
  v18.Matrix_1.M[0][2] = 0.0;
  v18.Matrix_1.M[0][3] = 0.0;
  v18.Matrix_1.M[1][0] = 0.0;
  v18.Matrix_1.M[1][2] = 0.0;
  v18.Matrix_1.M[1][3] = 0.0;
  v18.Matrix_1.M[1][1] = 1.0;
  v18.pFilters.pObject = 0;
  v18.CharacterId.Id = 0x40000;
  v18.Depth = 0;
  v18.Ratio = 0.0;
  memset(&v18.ClassName, 0, 9);
  Unpack(this, (Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *)&v18);
  if ( v21 )
  {
    if ( v21 == 1 )
    {
      Scaleform::GFx::DisplayObjContainer::MoveDisplayObject(m, &v18);
      goto LABEL_27;
    }
    if ( v21 != 2 )
      goto LABEL_27;
    StringManager = Scaleform::GFx::InteractiveObject::GetStringManager(m);
    if ( v20 )
    {
      v8 = 8;
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager, v20);
      ++StringNode->RefCount;
      v15 = StringNode;
      p_EmptyStringNode = StringNode;
    }
    else
    {
      ++StringManager->EmptyStringNode.RefCount;
      p_EmptyStringNode = &StringManager->EmptyStringNode;
      v15 = &StringManager->EmptyStringNode;
      StringNode = &StringManager->EmptyStringNode;
      v8 = 4;
    }
    v16 = v15;
    ++v15->RefCount;
    if ( (v8 & 8) != 0 )
    {
      v8 &= ~8u;
      v9 = StringNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    }
    if ( (v8 & 4) != 0 )
    {
      v9 = p_EmptyStringNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
    }
    m->CreateAndReplaceDisplayObject(
      m,
      &v18,
      (const Scaleform::GFx::ASString *)&v16,
      (Scaleform::GFx::DisplayObjectBase **)v17);
    v10 = v16;
  }
  else
  {
    v11 = Scaleform::GFx::InteractiveObject::GetStringManager(m);
    if ( v20 )
    {
      v13 = 2;
      v14 = Scaleform::GFx::ASStringManager::CreateStringNode(v11, v20);
      ++v14->RefCount;
      v16 = v14;
      v12 = v14;
    }
    else
    {
      v12 = &v11->EmptyStringNode;
      v13 = 1;
      ++v11->EmptyStringNode.RefCount;
      v16 = &v11->EmptyStringNode;
      v14 = &v11->EmptyStringNode;
    }
    v15 = v16;
    ++v16->RefCount;
    if ( (v13 & 2) != 0 )
    {
      v13 &= ~2u;
      v9 = v14->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    if ( (v13 & 1) != 0 )
    {
      v9 = v12->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    }
    m->AddDisplayObject(m, &v18, (const Scaleform::GFx::ASString *)&v15, v19, 0, -1u, 4u, 0, 0);
    v10 = v15;
  }
  if ( !--v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
LABEL_27:
  if ( v18.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v18.pFilters.pObject);
}
