void __thiscall Scaleform::GFx::PlaceObjectTag::Execute(
        Scaleform::GFx::PlaceObjectTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::PlaceObjectTag_vtbl *v3; // edx
  void (__thiscall *Unpack)(Scaleform::GFx::GFxPlaceObjectBase *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *); // edx
  Scaleform::GFx::ASStringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // [esp+7Ch] [ebp-74h] BYREF
  Scaleform::Render::Cxform v8; // [esp+80h] [ebp-70h] BYREF
  float v9; // [esp+A0h] [ebp-50h]
  float v10; // [esp+A4h] [ebp-4Ch]
  float v11; // [esp+A8h] [ebp-48h]
  float v12; // [esp+ACh] [ebp-44h]
  float v13; // [esp+B0h] [ebp-40h]
  float v14; // [esp+B4h] [ebp-3Ch]
  float v15; // [esp+B8h] [ebp-38h]
  float v16; // [esp+BCh] [ebp-34h]
  Scaleform::RefCountVImpl *v17; // [esp+C0h] [ebp-30h]
  float v18; // [esp+C4h] [ebp-2Ch]
  int v19; // [esp+C8h] [ebp-28h]
  int v20; // [esp+CCh] [ebp-24h]
  int v21; // [esp+D0h] [ebp-20h]
  __int16 v22; // [esp+D4h] [ebp-1Ch]
  __int16 v23; // [esp+D6h] [ebp-1Ah]
  char v24; // [esp+D8h] [ebp-18h]

  Scaleform::Render::Cxform::Cxform(&v8);
  v3 = this->__vftable;
  v9 = 1.0;
  Unpack = v3->Unpack;
  v10 = 0.0;
  v11 = 0.0;
  v12 = 0.0;
  v13 = 0.0;
  v23 = 0;
  v15 = 0.0;
  v16 = 0.0;
  v22 = 0;
  v14 = 1.0;
  v17 = 0;
  v20 = 0x40000;
  v19 = 0;
  v18 = 0.0;
  v24 = 0;
  v21 = 0;
  Unpack(this, (Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *)&v8);
  StringManager = Scaleform::GFx::InteractiveObject::GetStringManager(m);
  p_EmptyStringNode = &StringManager->EmptyStringNode;
  ++StringManager->EmptyStringNode.RefCount;
  m->AddDisplayObject(
    m,
    (const Scaleform::GFx::CharPosInfo *)&v8,
    (const Scaleform::GFx::ASString *)&p_EmptyStringNode,
    0,
    0,
    -1u,
    4u,
    0,
    0);
  v6 = p_EmptyStringNode;
  --p_EmptyStringNode->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
}
