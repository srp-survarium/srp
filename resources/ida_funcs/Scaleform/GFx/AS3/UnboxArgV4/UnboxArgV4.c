void __thiscall Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long>::UnboxArgV4<Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long>(
        Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const ,long,unsigned long,unsigned long,unsigned long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs4<long,unsigned long,unsigned long,unsigned long> *da)
{
  Scaleform::GFx::AS3::Value *v6; // ebp
  const Scaleform::GFx::AS3::DefArgs4<long,unsigned long,unsigned long,unsigned long> *v7; // edi

  v6 = argv;
  v7 = da;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,unsigned long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,unsigned long>(
    this,
    vm,
    result,
    argc,
    argv,
    da);
  this->a2 = v7->_2;
  if ( !vm->HandleException && argc > 2 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(v6 + 2, (Scaleform::GFx::AS3::CheckResult *)&da, &this->a2);
  this->a3 = v7->_3;
  if ( !vm->HandleException && argc > 3 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(v6 + 3, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->a3);
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,double,double,double,double>::UnboxArgV4<Scaleform::GFx::AS3::Value const,double,double,double,double>(
        Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const ,double,double,double,double> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs4<double,double,double,double> *da)
{
  Scaleform::GFx::AS3::Value *v6; // ebp
  const Scaleform::GFx::AS3::DefArgs4<double,double,double,double> *v7; // edi

  v6 = argv;
  v7 = da;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,double,double>::UnboxArgV2<Scaleform::GFx::AS3::Value const,double,double>(
    this,
    vm,
    result,
    argc,
    argv,
    da);
  this->a2 = v7->_2;
  if ( !vm->HandleException && argc > 2 )
    Scaleform::GFx::AS3::Value::Convert2Number(v6 + 2, (Scaleform::GFx::AS3::CheckResult *)&da, &this->a2);
  this->a3 = v7->_3;
  if ( !vm->HandleException && argc > 3 )
    Scaleform::GFx::AS3::Value::Convert2Number(v6 + 3, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->a3);
}
