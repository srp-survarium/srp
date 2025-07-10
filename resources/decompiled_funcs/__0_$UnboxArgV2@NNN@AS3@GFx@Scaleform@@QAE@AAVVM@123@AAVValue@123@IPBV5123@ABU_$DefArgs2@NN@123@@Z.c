void __thiscall Scaleform::GFx::AS3::UnboxArgV2<double,double,double>::UnboxArgV2<double,double,double>(
        Scaleform::GFx::AS3::UnboxArgV2<double,double,double> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<double,double> *da)
{
  Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::AS3::VM *v7; // edi
  const Scaleform::GFx::AS3::DefArgs2<double,double> *v9; // ebx
  unsigned int v10; // ebp

  v6 = result;
  v7 = vm;
  this->Vm = vm;
  this->Result = v6;
  this->r = Scaleform::GFx::NumberUtil::NaN();
  v9 = da;
  v10 = argc;
  this->a0 = da->_0;
  if ( v10 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  this->a1 = v9->_1;
  if ( !v7->HandleException && v10 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}
