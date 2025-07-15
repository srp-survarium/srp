void __thiscall survarium::flash_external_handler_impl::Callback(
        survarium::flash_external_handler_impl *this,
        Scaleform::GFx::Movie *pmovieView,
        const char *methodName,
        const Scaleform::GFx::Value *args,
        unsigned int argCount)
{
  survarium::flash_movie *v6; // eax

  v6 = (survarium::flash_movie *)pmovieView->GetUserData(pmovieView);
  this->owner->callback(this->owner, v6, methodName, (const survarium::flash_value *)args, argCount);
}
