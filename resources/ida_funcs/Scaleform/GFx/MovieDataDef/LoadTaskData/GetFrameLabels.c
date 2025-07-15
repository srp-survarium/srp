Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *__thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabels(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int frameNumber,
        Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *destArr)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v3; // ebx
  _DWORD *p_EntryCount; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  _DWORD *v8; // edx
  signed int v9; // edi
  int v10; // eax
  const Scaleform::String *v11; // eax
  const Scaleform::String *v12; // ebx
  unsigned int Size; // eax
  unsigned int v14; // esi
  Scaleform::String *v15; // ecx
  unsigned int v16; // eax
  _DWORD *v17; // ecx
  bool locked; // [esp+Bh] [ebp-11h]
  int i; // [esp+Ch] [ebp-10h]
  _DWORD *it; // [esp+14h] [ebp-8h]

  v3 = this;
  locked = 0;
  if ( this->LoadState < LS_LoadFinished )
  {
    EnterCriticalSection(&this->PlaylistLock.cs);
    locked = 1;
  }
  p_EntryCount = &v3->NamedFrames.mHash.pTable->EntryCount;
  if ( p_EntryCount )
  {
    v6 = p_EntryCount[1];
    v5 = 0;
    v7 = p_EntryCount + 2;
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 4;
    }
    while ( v5 <= v6 );
    p_EntryCount = &v3->NamedFrames.mHash.pTable;
  }
  else
  {
    v5 = 0;
  }
  v8 = p_EntryCount;
  it = p_EntryCount;
  v9 = v5;
  i = 0;
  while ( v8 )
  {
    v10 = *v8;
    if ( !*v8 || v9 > *(_DWORD *)(v10 + 4) )
      break;
    v11 = (const Scaleform::String *)(16 * v9 + v10);
    if ( frameNumber == v11[5].HeapTypeBits )
    {
      v12 = v11 + 4;
      Size = destArr->Data.Size;
      v14 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v14 >= destArr->Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)destArr,
            destArr,
            v14 + (v14 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::String>::DestructArray(&destArr->Data.Data[Size + 1], 0xFFFFFFFF);
        if ( v14 < destArr->Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)destArr,
            destArr,
            v14);
      }
      v15 = &destArr->Data.Data[v14 - 1];
      destArr->Data.Size = v14;
      if ( v15 )
        Scaleform::String::String(v15, v12);
      ++i;
      v3 = this;
      v8 = it;
    }
    v16 = *(_DWORD *)(*v8 + 4);
    if ( v9 <= (int)v16 && ++v9 <= v16 )
    {
      v17 = (_DWORD *)(16 * v9 + *v8 + 8);
      do
      {
        if ( *v17 != -2 )
          break;
        ++v9;
        v17 += 4;
      }
      while ( v9 <= v16 );
    }
  }
  if ( locked )
    LeaveCriticalSection(&v3->PlaylistLock.cs);
  return i != 0 ? destArr : 0;
}
