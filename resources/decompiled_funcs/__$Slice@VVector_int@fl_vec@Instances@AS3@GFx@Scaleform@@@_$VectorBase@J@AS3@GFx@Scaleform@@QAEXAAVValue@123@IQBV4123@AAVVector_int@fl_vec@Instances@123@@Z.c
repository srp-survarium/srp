void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v6; // ebx
  int v7; // ecx
  unsigned __int8 *Size; // eax
  bool v9; // sf
  int v10; // ebp
  bool v11; // zf
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v17; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v18; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *pObject; // [esp-4h] [ebp-28h]
  int endIndex; // [esp+10h] [ebp-14h] BYREF
  int startIndex; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VectorBase<long> *v22; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v23; // [esp+1Ch] [ebp-8h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *)currObj->pTraits.pObject;
  v22 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *)&currObj,
    pObject);
  v6 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  v7 = 0;
  Size = &vostok::memory::s_CRT_arena[5574199];
  startIndex = 0;
  endIndex = (int)&vostok::memory::s_CRT_arena[5574199];
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v7 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( argc > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
            argv + 1,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            (Scaleform::GFx::AS3::Value::V1U *)&endIndex)->Result )
      return;
    v7 = startIndex;
    Size = (unsigned __int8 *)endIndex;
  }
  if ( v7 < 0 )
  {
    v9 = (signed int)(this->ValueA.Data.Size + v7) < 0;
    v7 += this->ValueA.Data.Size;
    startIndex = v7;
    if ( v9 )
    {
      v7 = 0;
      startIndex = 0;
    }
  }
  if ( (int)Size < 0 )
  {
    Size += this->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  if ( (signed int)this->ValueA.Data.Size < (int)Size )
  {
    Size = (unsigned __int8 *)this->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  v10 = v7;
  if ( v7 < (int)Size )
  {
    do
    {
      v11 = !v6->V.Fixed;
      currObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)v22->ValueA.Data.Data[v10];
      if ( v11 )
        goto LABEL_19;
      VMRef = v6->V.VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v23, eVectorFixedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v13);
      pNode = v23.Message.pNode;
      --v23.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !v6->V.Fixed )
      {
LABEL_19:
        pHeap = v6->V.ValueA.Data.pHeap;
        p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v6->V.ValueA;
        v17 = v6->V.ValueA.Data.Size + 1;
        if ( v17 >= v6->V.ValueA.Data.Size )
        {
          if ( v17 >= v6->V.ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              pHeap,
              v17 + (v17 >> 2));
        }
        else if ( v17 < v6->V.ValueA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            pHeap,
            v6->V.ValueA.Data.Size + 1);
        }
        v18 = &p_ValueA->Data[v17 - 1];
        v6->V.ValueA.Data.Size = v17;
        if ( v18 )
          *v18 = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)currObj;
      }
      ++v10;
    }
    while ( v10 < endIndex );
  }
}
