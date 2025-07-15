void __thiscall Scaleform::GFx::PlaceObjectTag::Execute(
        Scaleform::GFx::PlaceObjectTag *this,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::PlaceObjectTag_vtbl *v3; // edx
  void (__thiscall *Unpack)(Scaleform::GFx::GFxPlaceObjectBase *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *); // edx
  Scaleform::GFx::ASStringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // [esp+24h] [ebp-74h] BYREF
  Scaleform::Render::Cxform v8; // [esp+28h] [ebp-70h] BYREF
  float v9; // [esp+48h] [ebp-50h]
  float v10; // [esp+4Ch] [ebp-4Ch]
  float v11; // [esp+50h] [ebp-48h]
  float v12; // [esp+54h] [ebp-44h]
  float v13; // [esp+58h] [ebp-40h]
  float v14; // [esp+5Ch] [ebp-3Ch]
  float v15; // [esp+60h] [ebp-38h]
  float v16; // [esp+64h] [ebp-34h]
  Scaleform::RefCountVImpl *v17; // [esp+68h] [ebp-30h]
  float v18; // [esp+6Ch] [ebp-2Ch]
  int v19; // [esp+70h] [ebp-28h]
  int v20; // [esp+74h] [ebp-24h]
  int v21; // [esp+78h] [ebp-20h]
  __int16 v22; // [esp+7Ch] [ebp-1Ch]
  __int16 v23; // [esp+7Eh] [ebp-1Ah]
  char v24; // [esp+80h] [ebp-18h]

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
