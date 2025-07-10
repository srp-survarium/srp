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
