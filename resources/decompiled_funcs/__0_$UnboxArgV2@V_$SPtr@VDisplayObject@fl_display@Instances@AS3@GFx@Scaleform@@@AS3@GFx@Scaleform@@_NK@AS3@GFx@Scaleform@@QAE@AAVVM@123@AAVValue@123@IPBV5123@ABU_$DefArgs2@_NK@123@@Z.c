void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,bool,unsigned long>::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,bool,unsigned long>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,bool,unsigned long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<bool,unsigned long> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<bool,unsigned long> *v6; // ebx

  v6 = da;
  this->Vm = vm;
  this->Result = result;
  this->r.pObject = 0;
  this->a0 = v6->_0;
  if ( argc )
    this->a0 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  this->a1 = v6->_1;
  if ( !vm->HandleException && argc > 1 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}
