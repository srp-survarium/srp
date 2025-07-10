char __thiscall Scaleform::Render::BlendModeEffect::Update(
        Scaleform::Render::BlendModeEffect *this,
        const Scaleform::Render::State *stateArg)
{
  void *pData; // eax

  pData = stateArg->pData;
  if ( this->StartEntry.Key.Data == pData )
    return 0;
  this->StartEntry.Key.Data = pData;
  return 1;
}
