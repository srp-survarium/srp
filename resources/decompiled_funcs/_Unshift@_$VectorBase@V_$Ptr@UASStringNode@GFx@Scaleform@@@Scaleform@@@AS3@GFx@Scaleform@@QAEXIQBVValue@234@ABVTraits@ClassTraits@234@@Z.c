void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Unshift(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v4; // edi
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebp
  Scaleform::GFx::AS3::Value::VU *p_value; // ebx
  Scaleform::GFx::ASStringNode *VInt; // esi
  Scaleform::GFx::ASStringNode **p_pObject; // ebp
  Scaleform::GFx::ASStringNode *v10; // ecx
  Scaleform::GFx::AS3::CheckResult result; // [esp+Ah] [ebp-6h] BYREF
  Scaleform::GFx::AS3::CheckResult v13; // [esp+Bh] [ebp-5h] BYREF
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *v14; // [esp+Ch] [ebp-4h]

  v4 = 0;
  v14 = 0;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result
    && Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(this, &v13, argc, argv, tr)->Result )
  {
    p_ValueA = &this->ValueA;
    tr = 0;
    v14 = &this->ValueA;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
      &this->ValueA,
      0,
      argc,
      (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&tr);
    if ( argc )
    {
      p_value = &argv->value;
      while ( 1 )
      {
        VInt = (Scaleform::GFx::ASStringNode *)p_value->VS._1.VInt;
        p_pObject = &p_ValueA->Data.Data[v4].pObject;
        if ( p_value->VS._1.VInt )
          ++VInt->RefCount;
        v10 = *p_pObject;
        if ( *p_pObject )
        {
          if ( v10->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        }
        ++v4;
        p_value += 2;
        *p_pObject = VInt;
        if ( v4 >= argc )
          break;
        p_ValueA = v14;
      }
    }
  }
}
