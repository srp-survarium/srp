void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj)
{
  int v5; // ebx
  int v6; // ecx
  unsigned __int8 *Size; // eax
  bool v8; // sf
  int v9; // edx
  bool v10; // zf
  Scaleform::GFx::AS3::VM *v11; // esi
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const void *v14; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v15; // edi
  unsigned int v16; // esi
  double *v17; // eax
  Scaleform::GFx::AS3::CheckResult v18; // [esp+Fh] [ebp-21h] BYREF
  int endIndex; // [esp+10h] [ebp-20h] BYREF
  int startIndex; // [esp+14h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::VectorBase<double> *v21; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS3::VM::Error v23; // [esp+20h] [ebp-10h] BYREF
  double v24; // [esp+28h] [ebp-8h]

  v21 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)&i,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *)currObj->pTraits.pObject);
  v5 = i;
  Scaleform::GFx::AS3::Value::Pick(result, (Scaleform::GFx::AS3::Object *)i);
  v6 = 0;
  Size = &vostok::memory::s_CRT_arena[5574199];
  startIndex = 0;
  endIndex = (int)&vostok::memory::s_CRT_arena[5574199];
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &v18, (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v6 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( argc > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, &v18, (Scaleform::GFx::AS3::Value::V1U *)&endIndex)->Result )
      return;
    v6 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( v6 < 0 )
  {
    v8 = (signed int)(v21->ValueA.Data.Size + v6) < 0;
    v6 += v21->ValueA.Data.Size;
    startIndex = v6;
    if ( v8 )
    {
      v6 = 0;
      startIndex = 0;
    }
  }
  if ( (int)Size < 0 )
  {
    Size += v21->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  if ( (signed int)v21->ValueA.Data.Size < (int)Size )
  {
    Size = (unsigned __int8 *)v21->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  v9 = v6;
  i = v6;
  if ( v6 < (int)Size )
  {
    do
    {
      v10 = *(_BYTE *)(v5 + 36) == 0;
      v24 = v21->ValueA.Data.Data[v9];
      if ( v10 )
        goto LABEL_19;
      v11 = *(Scaleform::GFx::AS3::VM **)(v5 + 40);
      Scaleform::GFx::AS3::VM::Error::Error(&v23, eVectorFixedError, v11);
      Scaleform::GFx::AS3::VM::ThrowRangeError(v11, v12);
      pNode = v23.Message.pNode;
      --v23.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !*(_BYTE *)(v5 + 36) )
      {
LABEL_19:
        v14 = *(const void **)(v5 + 56);
        v15 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)(v5 + 44);
        v16 = *(_DWORD *)(v5 + 48) + 1;
        if ( v16 >= *(_DWORD *)(v5 + 48) )
        {
          if ( v16 >= *(_DWORD *)(v5 + 52) )
            Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v15,
              v14,
              v16 + (v16 >> 2));
        }
        else if ( v16 < *(_DWORD *)(v5 + 52) >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v15,
            v14,
            *(_DWORD *)(v5 + 48) + 1);
        }
        v17 = (double *)&v15->Data[v16 - 1];
        *(_DWORD *)(v5 + 48) = v16;
        if ( v17 )
          *v17 = v24;
      }
      v9 = ++i;
    }
    while ( i < endIndex );
  }
}
