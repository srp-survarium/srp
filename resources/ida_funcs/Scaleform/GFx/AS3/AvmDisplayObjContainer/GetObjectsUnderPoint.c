bool __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetObjectsUnderPoint(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *destArray,
        const Scaleform::Render::Point<float> *pt)
{
  Scaleform::GFx::DisplayObjContainer *pDispObj; // edi
  Scaleform::GFx::DisplayObject *Mask; // esi
  const Scaleform::Render::Matrix2x4<float> *WorldMatrix; // eax
  const Scaleform::Render::Matrix2x4<float> *v7; // eax
  int v8; // edi
  unsigned int v9; // edx
  int v10; // eax
  int v11; // esi
  float *v12; // eax
  bool v13; // bl
  unsigned int Size; // [esp+2C0h] [ebp-68h]
  int v15; // [esp+2C0h] [ebp-68h]
  Scaleform::GFx::DisplayObjContainer *v16; // [esp+2C4h] [ebp-64h]
  unsigned int v17; // [esp+2C8h] [ebp-60h]
  float x; // [esp+2CCh] [ebp-5Ch] BYREF
  float y; // [esp+2D0h] [ebp-58h]
  Scaleform::Render::Point<float> v20; // [esp+2D4h] [ebp-54h] BYREF
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> phitTest; // [esp+2DCh] [ebp-4Ch] BYREF
  Scaleform::Render::Matrix2x4<float> v22; // [esp+2E8h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+308h] [ebp-20h] BYREF

  pDispObj = (Scaleform::GFx::DisplayObjContainer *)this->pDispObj;
  v16 = pDispObj;
  if ( !pDispObj->GetVisible(pDispObj) )
    return 0;
  Size = pDispObj->mDisplayList.DisplayObjectArray.Data.Size;
  Mask = Scaleform::GFx::DisplayObject::GetMask(pDispObj);
  if ( Mask )
  {
    if ( Mask->IsUsedAsMask(Mask) && (Mask->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
    {
      v22.M[0][0] = 1.0;
      v22.M[0][1] = 0.0;
      v22.M[0][2] = 0.0;
      v22.M[0][3] = 0.0;
      v22.M[1][0] = 0.0;
      v22.M[1][2] = 0.0;
      v22.M[1][3] = 0.0;
      v22.M[1][1] = 1.0;
      WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(Mask, &result);
      Scaleform::Render::Matrix2x4<float>::SetInverse(&v22, WorldMatrix);
      v7 = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pDispObj, &result);
      Scaleform::Render::Matrix2x4<float>::Prepend(&v22, v7);
      Scaleform::Render::Matrix2x4<float>::Transform(&v22, &v20, pt);
      if ( !Mask->PointTestLocal(Mask, &v20, 3u) )
        return 0;
    }
  }
  memset(&phitTest, 0, sizeof(phitTest));
  Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(pDispObj, &phitTest, pt, 1);
  v22.M[0][0] = 1.0;
  v8 = Size - 1;
  v22.M[0][1] = 0.0;
  v9 = destArray->Data.Size;
  v22.M[0][2] = 0.0;
  v22.M[0][3] = 0.0;
  v17 = v9;
  v22.M[1][0] = 0.0;
  v22.M[1][2] = 0.0;
  v22.M[1][3] = 0.0;
  v22.M[1][1] = 1.0;
  x = pt->x;
  y = pt->y;
  if ( (int)(Size - 1) >= 0 )
  {
    v10 = 12 * v8;
    v15 = 12 * v8;
    do
    {
      v11 = *(int *)((char *)&v16->mDisplayList.DisplayObjectArray.Data.Data->pCharacter + v10);
      if ( (*(_BYTE *)(v11 + 63) & 1) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 228))(v11)
        && (!phitTest.Data.Size || phitTest.Data.Data[v8] && !*(_WORD *)(v11 + 60)) )
      {
        v12 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 8))(v11);
        v22.M[0][0] = *v12;
        v22.M[0][1] = v12[1];
        v22.M[0][2] = v12[2];
        v22.M[0][3] = v12[3];
        v22.M[1][0] = v12[4];
        v22.M[1][1] = v12[5];
        v22.M[1][2] = v12[6];
        v22.M[1][3] = v12[7];
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v22, &v20, pt);
        x = v20.x;
        y = v20.y;
        (*(void (__thiscall **)(int, Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *, float *))(*(_DWORD *)(v11 + 4 * *(unsigned __int8 *)(v11 + 65)) + 80))(
          v11 + 4 * *(unsigned __int8 *)(v11 + 65),
          destArray,
          &x);
      }
      --v8;
      v10 = v15 - 12;
      v15 -= 12;
    }
    while ( v8 >= 0 );
  }
  v13 = destArray->Data.Size > v17;
  if ( phitTest.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, phitTest.Data.Data);
  return v13;
}
