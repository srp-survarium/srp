void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,unsigned long,double>::UnboxArgV2<Scaleform::GFx::AS3::Value const,unsigned long,double>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,unsigned long,double> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<unsigned long,double> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<unsigned long,double> *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::VM *v9; // edi

  v6 = da;
  v7 = argc;
  v9 = vm;
  this->r = result;
  this->Vm = v9;
  this->a0 = v6->_0;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v6->_1;
  if ( !v9->HandleException && v7 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}
