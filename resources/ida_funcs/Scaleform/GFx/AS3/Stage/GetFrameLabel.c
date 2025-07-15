const Scaleform::String *__thiscall Scaleform::GFx::AS3::Stage::GetFrameLabel(
        Scaleform::GFx::AS3::Stage *this,
        unsigned int fr,
        unsigned int *pdestfr)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // ecx

  pObject = this->pRoot.pObject;
  if ( pObject )
    return pObject->GetFrameLabel(pObject, fr, pdestfr);
  else
    return 0;
}
