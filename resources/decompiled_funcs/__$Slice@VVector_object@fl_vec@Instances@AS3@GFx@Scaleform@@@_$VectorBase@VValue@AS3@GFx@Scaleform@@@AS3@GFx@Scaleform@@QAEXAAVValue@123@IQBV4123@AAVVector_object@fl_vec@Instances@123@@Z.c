void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *currObj)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v5; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v6; // ebx
  int v7; // eax
  unsigned __int8 *Size; // ecx
  bool v9; // sf
  int v10; // ebp
  Scaleform::GFx::AS3::Value *v11; // edi
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *pObject; // [esp-4h] [ebp-28h]
  int endIndex; // [esp+10h] [ebp-14h] BYREF
  int startIndex; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v18; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v19; // [esp+1Ch] [ebp-8h] BYREF

  v5 = this;
  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *)currObj->pTraits.pObject;
  v18 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&currObj,
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
    v9 = (signed int)(v5->ValueA.Data.Size + v7) < 0;
    v7 += v5->ValueA.Data.Size;
    startIndex = v7;
    if ( v9 )
    {
      v7 = 0;
      startIndex = 0;
    }
  }
  if ( (int)Size < 0 )
  {
    Size += v5->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  if ( (signed int)v5->ValueA.Data.Size < (int)Size )
  {
    Size = (unsigned __int8 *)v5->ValueA.Data.Size;
    endIndex = (int)Size;
  }
  currObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v7;
  if ( v7 < (int)Size )
  {
    v10 = v7;
    while ( 1 )
    {
      v11 = &v5->ValueA.Data.Data[v10];
      if ( !v6->V.Fixed )
        goto LABEL_21;
      VMRef = v6->V.VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eVectorFixedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v13);
      pNode = v19.Message.pNode;
      --v19.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !v6->V.Fixed )
LABEL_21:
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &v6->V.ValueA.Data,
          v11);
      ++v10;
      currObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)currObj + 1);
      if ( (int)currObj >= endIndex )
        break;
      v5 = v18;
    }
  }
}
