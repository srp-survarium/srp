void __thiscall survarium::flash_function_handler_impl::Call(
        survarium::flash_function_handler_impl *this,
        const Scaleform::GFx::FunctionHandler::Params *params)
{
  Scaleform::GFx::Movie *pMovie; // eax
  int v4; // eax
  survarium::flash_function_handler *owner; // ecx
  _DWORD v6[4]; // [esp+4h] [ebp-10h] BYREF

  v6[0] = params->pRetVal;
  v6[1] = params->pArgs;
  pMovie = params->pMovie;
  v6[3] = params->ArgCount;
  v4 = (int)pMovie->GetUserData(pMovie);
  owner = this->owner;
  v6[2] = v4;
  owner->scaleform_call(owner, (survarium::flash_function_handler_params *)v6);
}
