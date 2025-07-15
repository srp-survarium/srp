void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj)
{
  int v6; // eax
  unsigned int Size; // esi
  Scaleform::GFx::ASStringNode *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v11; // ebp
  unsigned int v12; // eax
  Scaleform::GFx::AS3::CheckResult v13; // [esp+7h] [ebp-31h] BYREF
  int startIndex; // [esp+8h] [ebp-30h] BYREF
  unsigned int deleteCount; // [esp+Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v16; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value arg1; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value arg2; // [esp+28h] [ebp-10h] BYREF

  if ( !Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v13)->Result )
    return;
  v6 = 0;
  startIndex = 0;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &v13, (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v6 = startIndex;
  }
  Size = this->ValueA.Data.Size;
  deleteCount = 0;
  if ( v6 < 0 )
  {
    v6 += Size;
    startIndex = v6;
  }
  if ( argc <= 1 )
  {
    deleteCount = Size - v6;
  }
  else
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 1, &v13, (Scaleform::GFx::AS3::Value::V1U *)&deleteCount)->Result )
      return;
    if ( (int)(startIndex + deleteCount) < 0 || startIndex + deleteCount > Size )
    {
      arg2.value.VS._1.VInt = Size;
      VMRef = (Scaleform::GFx::ASStringNode *)this->VMRef;
      arg2.Flags = 3;
      arg2.Bonus.pWeakProxy = 0;
      arg1.Flags = 2;
      arg1.Bonus.pWeakProxy = 0;
      arg1.value.VS._1.VInt = startIndex + deleteCount;
      Scaleform::GFx::AS3::VM::Error::Error(&v16, (Scaleform::GFx::AS3::VM_vtbl *)0x465, VMRef, &arg1, &arg2);
      Scaleform::GFx::AS3::VM::ThrowRangeError((Scaleform::GFx::AS3::VM *)VMRef, v9);
      pNode = v16.Message.pNode;
      --v16.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( (arg1.Flags & 0x1F) > 9 )
      {
        if ( (arg1.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&arg1);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&arg1);
      }
      if ( (arg2.Flags & 0x1F) > 9 )
      {
        if ( (arg2.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&arg2);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&arg2);
      }
      return;
    }
  }
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)&currObj,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *)currObj->pTraits.pObject);
  v11 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  if ( startIndex <= (int)Size && startIndex >= 0 )
  {
    Scaleform::GFx::AS3::VectorBase<double>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
      this,
      startIndex,
      deleteCount,
      v11);
    if ( argc > 2 )
    {
      v12 = startIndex;
      if ( (signed int)this->ValueA.Data.Size < startIndex )
      {
        v12 = this->ValueA.Data.Size;
        startIndex = v12;
      }
      Scaleform::GFx::AS3::VectorBase<double>::Insert(this, v12, argc - 2, argv + 2);
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  int v6; // eax
  unsigned int Size; // esi
  Scaleform::GFx::ASStringNode *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v11; // ebp
  unsigned int v12; // eax
  Scaleform::GFx::AS3::CheckResult v13; // [esp+7h] [ebp-31h] BYREF
  int startIndex; // [esp+8h] [ebp-30h] BYREF
  unsigned int deleteCount; // [esp+Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v16; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value arg1; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value arg2; // [esp+28h] [ebp-10h] BYREF

  if ( !Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v13)->Result )
    return;
  v6 = 0;
  startIndex = 0;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &v13, (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v6 = startIndex;
  }
  Size = this->ValueA.Data.Size;
  deleteCount = 0;
  if ( v6 < 0 )
  {
    v6 += Size;
    startIndex = v6;
  }
  if ( argc <= 1 )
  {
    deleteCount = Size - v6;
  }
  else
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 1, &v13, (Scaleform::GFx::AS3::Value::V1U *)&deleteCount)->Result )
      return;
    if ( (int)(startIndex + deleteCount) < 0 || startIndex + deleteCount > Size )
    {
      arg2.value.VS._1.VInt = Size;
      VMRef = (Scaleform::GFx::ASStringNode *)this->VMRef;
      arg2.Flags = 3;
      arg2.Bonus.pWeakProxy = 0;
      arg1.Flags = 2;
      arg1.Bonus.pWeakProxy = 0;
      arg1.value.VS._1.VInt = startIndex + deleteCount;
      Scaleform::GFx::AS3::VM::Error::Error(&v16, (Scaleform::GFx::AS3::VM_vtbl *)0x465, VMRef, &arg1, &arg2);
      Scaleform::GFx::AS3::VM::ThrowRangeError((Scaleform::GFx::AS3::VM *)VMRef, v9);
      pNode = v16.Message.pNode;
      --v16.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( (arg1.Flags & 0x1F) > 9 )
      {
        if ( (arg1.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&arg1);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&arg1);
      }
      if ( (arg2.Flags & 0x1F) > 9 )
      {
        if ( (arg2.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&arg2);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&arg2);
      }
      return;
    }
  }
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *)&currObj,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *)currObj->pTraits.pObject);
  v11 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  if ( startIndex <= (int)Size && startIndex >= 0 )
  {
    Scaleform::GFx::AS3::VectorBase<unsigned long>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
      (Scaleform::GFx::AS3::VectorBase<unsigned long> *)this,
      startIndex,
      deleteCount,
      v11);
    if ( argc > 2 )
    {
      v12 = startIndex;
      if ( (signed int)this->ValueA.Data.Size < startIndex )
      {
        v12 = this->ValueA.Data.Size;
        startIndex = v12;
      }
      Scaleform::GFx::AS3::VectorBase<long>::Insert(
        (Scaleform::GFx::AS3::VectorBase<unsigned long> *)this,
        v12,
        (Scaleform::GFx::AS3::Value::V1U)(argc - 2),
        argv + 2);
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  int v6; // eax
  unsigned int Size; // esi
  Scaleform::GFx::ASStringNode *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v11; // ebp
  unsigned int v12; // eax
  Scaleform::GFx::AS3::CheckResult v13; // [esp+7h] [ebp-31h] BYREF
  int startIndex; // [esp+8h] [ebp-30h] BYREF
  unsigned int deleteCount; // [esp+Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v16; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value arg1; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value arg2; // [esp+28h] [ebp-10h] BYREF

  if ( !Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v13)->Result )
    return;
  v6 = 0;
  startIndex = 0;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &v13, (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
      return;
    v6 = startIndex;
  }
  Size = this->ValueA.Data.Size;
  deleteCount = 0;
  if ( v6 < 0 )
  {
    v6 += Size;
    startIndex = v6;
  }
  if ( argc <= 1 )
  {
    deleteCount = Size - v6;
  }
  else
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 1, &v13, (Scaleform::GFx::AS3::Value::V1U *)&deleteCount)->Result )
      return;
    if ( (int)(startIndex + deleteCount) < 0 || startIndex + deleteCount > Size )
    {
      arg2.value.VS._1.VInt = Size;
      VMRef = (Scaleform::GFx::ASStringNode *)this->VMRef;
      arg2.Flags = 3;
      arg2.Bonus.pWeakProxy = 0;
      arg1.Flags = 2;
      arg1.Bonus.pWeakProxy = 0;
      arg1.value.VS._1.VInt = startIndex + deleteCount;
      Scaleform::GFx::AS3::VM::Error::Error(&v16, (Scaleform::GFx::AS3::VM_vtbl *)0x465, VMRef, &arg1, &arg2);
      Scaleform::GFx::AS3::VM::ThrowRangeError((Scaleform::GFx::AS3::VM *)VMRef, v9);
      pNode = v16.Message.pNode;
      --v16.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( (arg1.Flags & 0x1F) > 9 )
      {
        if ( (arg1.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&arg1);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&arg1);
      }
      if ( (arg2.Flags & 0x1F) > 9 )
      {
        if ( (arg2.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&arg2);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&arg2);
      }
      return;
    }
  }
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&currObj,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *)currObj->pTraits.pObject);
  v11 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  if ( startIndex <= (int)Size && startIndex >= 0 )
  {
    Scaleform::GFx::AS3::VectorBase<unsigned long>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
      this,
      startIndex,
      deleteCount,
      v11);
    if ( argc > 2 )
    {
      v12 = startIndex;
      if ( (signed int)this->ValueA.Data.Size < startIndex )
      {
        v12 = this->ValueA.Data.Size;
        startIndex = v12;
      }
      Scaleform::GFx::AS3::VectorBase<long>::Insert(this, v12, (Scaleform::GFx::AS3::Value::V1U)(argc - 2), argv + 2);
    }
  }
}
