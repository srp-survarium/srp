void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Object *argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj)
{
  Scaleform::GFx::AS3::Object *v6; // ebp
  int v7; // eax
  unsigned int Size; // edi
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v12; // ebx
  unsigned int v13; // eax
  Scaleform::GFx::AS3::CheckResult v14; // [esp+7h] [ebp-11h] BYREF
  int startIndex; // [esp+8h] [ebp-10h] BYREF
  unsigned int deleteCount; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v17; // [esp+10h] [ebp-8h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v14)->Result )
  {
    v6 = argc;
    v7 = 0;
    startIndex = 0;
    if ( argc )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2Int32(
              argv,
              (Scaleform::GFx::AS3::CheckResult *)&argc,
              (Scaleform::GFx::AS3::Value::V1U *)&startIndex)->Result )
        return;
      v7 = startIndex;
    }
    Size = this->ValueA.Data.Size;
    deleteCount = 0;
    if ( v7 < 0 )
    {
      v7 += Size;
      startIndex = v7;
    }
    if ( (unsigned int)v6 <= 1 )
    {
      deleteCount = Size - v7;
    }
    else
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(
              argv + 1,
              (Scaleform::GFx::AS3::CheckResult *)&argc,
              (Scaleform::GFx::AS3::Value::V1U *)&deleteCount)->Result )
        return;
      if ( (int)(startIndex + deleteCount) < 0 || startIndex + deleteCount > Size )
      {
        VMRef = this->VMRef;
        Scaleform::GFx::AS3::VM::Error::Error(&v17, eOutOfRangeError, VMRef);
        Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v10);
        pNode = v17.Message.pNode;
        --v17.Message.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        return;
      }
    }
    Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)&argc,
      (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *)currObj->pTraits.pObject);
    v12 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)argc;
    Scaleform::GFx::AS3::Value::Pick(result, argc);
    if ( startIndex <= (int)Size && startIndex >= 0 )
    {
      Scaleform::GFx::AS3::VectorBase<double>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        this,
        startIndex,
        deleteCount,
        v12);
      if ( (unsigned int)v6 > 2 )
      {
        v13 = startIndex;
        if ( (signed int)this->ValueA.Data.Size < startIndex )
        {
          v13 = this->ValueA.Data.Size;
          startIndex = v13;
        }
        Scaleform::GFx::AS3::VectorBase<double>::Insert(this, v13, (unsigned int)&v6[-1].pUserDataHolder + 2, argv + 2);
      }
    }
  }
}
