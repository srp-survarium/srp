void __thiscall Scaleform::GFx::AS3::UnboxArgV6<Scaleform::GFx::AS3::Value const,double,double,double,double,double,double>::UnboxArgV6<Scaleform::GFx::AS3::Value const,double,double,double,double,double,double>(
        Scaleform::GFx::AS3::UnboxArgV6<Scaleform::GFx::AS3::Value const ,double,double,double,double,double,double> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs6<double,double,double,double,double,double> *da)
{
  Scaleform::GFx::AS3::Value *v6; // ebp
  const Scaleform::GFx::AS3::DefArgs6<double,double,double,double,double,double> *v7; // edi

  v6 = argv;
  v7 = da;
  Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,double,double,double,double>::UnboxArgV4<Scaleform::GFx::AS3::Value const,double,double,double,double>(
    this,
    vm,
    result,
    argc,
    argv,
    da);
  this->a4 = v7->_4;
  if ( !vm->HandleException && argc > 4 )
    Scaleform::GFx::AS3::Value::Convert2Number(v6 + 4, (Scaleform::GFx::AS3::CheckResult *)&da, &this->a4);
  this->a5 = v7->_5;
  if ( !vm->HandleException && argc > 5 )
    Scaleform::GFx::AS3::Value::Convert2Number(v6 + 5, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->a5);
}
