void __thiscall survarium::flash_function_handler_impl::Call(
        survarium::flash_function_handler_impl *this,
        const Scaleform::GFx::FunctionHandler::Params *params)
{
  Scaleform::GFx::Value *pArgs; // edx
  Scaleform::GFx::Movie *pMovie; // eax
  survarium::flash_movie *v5; // eax
  survarium::flash_function_handler *owner; // ecx
  survarium::flash_function_handler_params p; // [esp+4h] [ebp-10h] BYREF

  pArgs = params->pArgs;
  p.pRetVal = (survarium::flash_value *)params->pRetVal;
  pMovie = params->pMovie;
  p.ArgCount = params->ArgCount;
  p.pArgs = (survarium::flash_value *)pArgs;
  v5 = (survarium::flash_movie *)pMovie->GetUserData(pMovie);
  owner = this->owner;
  p.pMovie = v5;
  owner->call(owner, &p);
}
