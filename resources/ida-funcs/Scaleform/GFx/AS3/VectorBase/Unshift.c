void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Unshift(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v6; // eax
  Scaleform::GFx::AS3::Value::VU *p_value; // ecx
  Scaleform::GFx::AS3::CheckResult result; // [esp+Ah] [ebp-6h] BYREF
  Scaleform::GFx::AS3::CheckResult v9; // [esp+Bh] [ebp-5h] BYREF
  int v10; // [esp+Ch] [ebp-4h]

  v10 = 0;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result
    && Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(this, &v9, argc, argv, tr)->Result )
  {
    p_ValueA = &this->ValueA;
    tr = 0;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
      p_ValueA,
      0,
      argc,
      (unsigned int *)&tr);
    v6 = 0;
    if ( argc )
    {
      p_value = &argv->value;
      do
      {
        p_ValueA->Data.Data[v6++] = p_value->VS._1.VInt;
        p_value += 2;
      }
      while ( v6 < argc );
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Unshift(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  const Scaleform::GFx::AS3::Value *v5; // ebx
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
  unsigned int v7; // eax
  double *p_VNumber; // ecx
  double v9; // st7
  double *v10; // ecx
  Scaleform::GFx::AS3::CheckResult result; // [esp+Eh] [ebp-Ah] BYREF
  Scaleform::GFx::AS3::CheckResult v12; // [esp+Fh] [ebp-9h] BYREF
  double val; // [esp+10h] [ebp-8h] BYREF

  LODWORD(val) = 0;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v5 = argv;
    if ( Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(this, &v12, argc, argv, tr)->Result )
    {
      val = 0.0;
      p_ValueA = &this->ValueA;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
        p_ValueA,
        0,
        argc,
        &val);
      v7 = 0;
      if ( argc >= 4 )
      {
        p_VNumber = &argv[1].value.VNumber;
        do
        {
          p_ValueA->Data.Data[v7] = *(p_VNumber - 2);
          v7 += 4;
          p_ValueA->Data.Data[v7 - 3] = *p_VNumber;
          v9 = p_VNumber[2];
          p_VNumber += 8;
          p_ValueA->Data.Data[v7 - 2] = v9;
          p_ValueA->Data.Data[v7 - 1] = *(p_VNumber - 4);
        }
        while ( v7 < argc - 3 );
        v5 = argv;
      }
      if ( v7 < argc )
      {
        v10 = &v5[v7].value.VNumber;
        do
        {
          p_ValueA->Data.Data[v7++] = *v10;
          v10 += 2;
        }
        while ( v7 < argc );
      }
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Unshift(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Value *v6; // edi
  Scaleform::GFx::AS3::CheckResult result; // [esp+Ah] [ebp-16h] BYREF
  Scaleform::GFx::AS3::CheckResult v8; // [esp+Bh] [ebp-15h] BYREF
  int v9; // [esp+Ch] [ebp-14h]
  Scaleform::GFx::AS3::Value val; // [esp+10h] [ebp-10h] BYREF

  v4 = 0;
  v9 = 0;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v6 = argv;
    if ( Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(this, &v8, argc, argv, tr)->Result )
    {
      val.Flags = 0;
      val.Bonus.pWeakProxy = 0;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
        &this->ValueA,
        0,
        argc,
        &val);
      if ( (val.Flags & 0x1F) > 9 )
      {
        if ( (val.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      }
      if ( argc )
      {
        do
          Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::SetUnsafe(this, v4++, v6++);
        while ( v4 < argc );
      }
    }
  }
}


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
