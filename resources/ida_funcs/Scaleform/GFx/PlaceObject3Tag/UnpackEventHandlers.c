Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *__thiscall Scaleform::GFx::PlaceObject3Tag::UnpackEventHandlers(
        Scaleform::GFx::PlaceObject3Tag *this)
{
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *result; // eax
  Scaleform::GFx::PlaceObject3Tag_vtbl *v3; // edx
  void (__thiscall *Unpack)(Scaleform::GFx::GFxPlaceObjectBase *, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *); // edx
  int v5; // esi
  Scaleform::Render::Cxform v6; // [esp+F0h] [ebp-70h] BYREF
  float v7; // [esp+110h] [ebp-50h]
  float v8; // [esp+114h] [ebp-4Ch]
  float v9; // [esp+118h] [ebp-48h]
  float v10; // [esp+11Ch] [ebp-44h]
  float v11; // [esp+120h] [ebp-40h]
  float v12; // [esp+124h] [ebp-3Ch]
  float v13; // [esp+128h] [ebp-38h]
  float v14; // [esp+12Ch] [ebp-34h]
  Scaleform::RefCountVImpl *v15; // [esp+130h] [ebp-30h]
  float v16; // [esp+134h] [ebp-2Ch]
  int v17; // [esp+138h] [ebp-28h]
  int v18; // [esp+13Ch] [ebp-24h]
  int v19; // [esp+140h] [ebp-20h]
  __int16 v20; // [esp+144h] [ebp-1Ch]
  __int16 v21; // [esp+146h] [ebp-1Ah]
  char v22; // [esp+148h] [ebp-18h]
  int v23; // [esp+150h] [ebp-10h]

  result = 0;
  if ( (this->pData[0] & 0x80u) != 0 )
  {
    result = *(Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> **)&this->pData[1];
    if ( !result )
    {
      Scaleform::Render::Cxform::Cxform(&v6);
      v3 = this->__vftable;
      v7 = 1.0;
      Unpack = v3->Unpack;
      v8 = 0.0;
      v9 = 0.0;
      v10 = 0.0;
      v21 = 0;
      v11 = 0.0;
      v13 = 0.0;
      v20 = 0;
      v14 = 0.0;
      v12 = 1.0;
      v15 = 0;
      v18 = 0x40000;
      v17 = 0;
      v22 = 0;
      v16 = 0.0;
      v19 = 0;
      Unpack(this, (Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *)&v6);
      v5 = v23;
      if ( v15 )
        Scaleform::RefCountImpl::Release(v15);
      return (Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *)v5;
    }
  }
  return result;
}
