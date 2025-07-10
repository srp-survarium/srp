bool __thiscall Scaleform::GFx::DisplayObjContainer::PointTestLocal(
        Scaleform::GFx::DisplayObjContainer *this,
        const Scaleform::Render::Point<float> *pt,
        int hitTestMask)
{
  Scaleform::Render::Rect<float> *(__thiscall *GetBounds)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // edx
  Scaleform::Render::Rect<float> *v5; // eax
  bool v6; // al
  Scaleform::GFx::DisplayObject *Mask; // esi
  const Scaleform::Render::Matrix2x4<float> *m; // eax
  const Scaleform::Render::Matrix2x4<float> *WorldMatrix; // eax
  int v10; // edi
  int v11; // eax
  _WORD *v12; // esi
  float *v13; // eax
  unsigned int Size; // [esp+188h] [ebp-54h]
  int v15; // [esp+188h] [ebp-54h]
  float x; // [esp+18Ch] [ebp-50h] BYREF
  float y; // [esp+190h] [ebp-4Ch]
  Scaleform::Render::Point<float> v18; // [esp+194h] [ebp-48h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+19Ch] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v20; // [esp+1BCh] [ebp-20h] BYREF

  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0x800) != 0 )
    return 0;
  if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 1) == 0 )
  {
    GetBounds = this->GetBounds;
    v20.M[0][0] = 1.0;
    v20.M[1][1] = 1.0;
    v20.M[0][1] = 0.0;
    v20.M[0][2] = 0.0;
    v20.M[0][3] = 0.0;
    v20.M[1][0] = 0.0;
    v20.M[1][2] = 0.0;
    v20.M[1][3] = 0.0;
    v5 = GetBounds(this, (Scaleform::Render::Rect<float> *)&result, &v20);
    v6 = Scaleform::Render::Rect<float>::Contains(v5, pt);
    if ( !v6 )
      return v6;
  }
  if ( (hitTestMask & 2) != 0 && !this->GetVisible(this) )
    return 0;
  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  Mask = Scaleform::GFx::DisplayObject::GetMask(this);
  if ( Mask )
  {
    if ( Mask->IsUsedAsMask(Mask) && (Mask->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
    {
      v20.M[0][0] = 1.0;
      v20.M[0][1] = 0.0;
      v20.M[0][2] = 0.0;
      v20.M[0][3] = 0.0;
      v20.M[1][0] = 0.0;
      v20.M[1][2] = 0.0;
      v20.M[1][3] = 0.0;
      v20.M[1][1] = 1.0;
      m = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(Mask, &result);
      Scaleform::Render::Matrix2x4<float>::SetInverse(&v20, m);
      WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, &result);
      Scaleform::Render::Matrix2x4<float>::Prepend(&v20, WorldMatrix);
      Scaleform::Render::Matrix2x4<float>::Transform(&v20, &v18, pt);
      if ( !Mask->PointTestLocal(Mask, &v18, hitTestMask) )
        return 0;
    }
  }
  memset(&result, 0, 12);
  Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(
    this,
    (Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&result,
    pt,
    hitTestMask & 1);
  v20.M[0][0] = 1.0;
  v20.M[0][1] = 0.0;
  v20.M[0][2] = 0.0;
  v20.M[0][3] = 0.0;
  v20.M[1][0] = 0.0;
  v20.M[1][2] = 0.0;
  v20.M[1][3] = 0.0;
  v20.M[1][1] = 1.0;
  x = pt->x;
  v10 = Size - 1;
  y = pt->y;
  if ( (int)(Size - 1) < 0 )
  {
LABEL_19:
    if ( LODWORD(result.M[0][0]) )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)LODWORD(result.M[0][0]));
    return 0;
  }
  v11 = 12 * v10;
  v15 = 12 * v10;
  while ( 1 )
  {
    v12 = *(Scaleform::GFx::DisplayObjectBase **)((char *)&this->mDisplayList.DisplayObjectArray.Data.Data->pCharacter
                                                + v11);
    if ( ((hitTestMask & 2) == 0 || (*(unsigned __int8 (__thiscall **)(_WORD *))(*(_DWORD *)v12 + 228))(v12))
      && (!LODWORD(result.M[0][1]) || *(_BYTE *)(LODWORD(result.M[0][0]) + v10) && !v12[30]) )
    {
      v13 = (float *)(*(int (__thiscall **)(_WORD *))(*(_DWORD *)v12 + 8))(v12);
      v20.M[0][0] = *v13;
      v20.M[0][1] = v13[1];
      v20.M[0][2] = v13[2];
      v20.M[0][3] = v13[3];
      v20.M[1][0] = v13[4];
      v20.M[1][1] = v13[5];
      v20.M[1][2] = v13[6];
      v20.M[1][3] = v13[7];
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v20, &v18, pt);
      x = v18.x;
      y = v18.y;
      if ( (*(unsigned __int8 (__thiscall **)(_WORD *, float *, int))(*(_DWORD *)v12 + 244))(v12, &x, hitTestMask) )
        break;
    }
    --v10;
    v11 = v15 - 12;
    v15 -= 12;
    if ( v10 < 0 )
      goto LABEL_19;
  }
  if ( LODWORD(result.M[0][0]) )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)LODWORD(result.M[0][0]));
  return 1;
}
