void __thiscall Scaleform::GFx::LoadStates::BuildURL(
        Scaleform::GFx::LoadStates *this,
        Scaleform::String *pdest,
        const Scaleform::GFx::URLBuilder::LocationInfo *loc)
{
  Scaleform::GFx::URLBuilder *pObject; // ecx

  pObject = this->pBindStates.pObject->pURLBulider.pObject;
  if ( pObject )
    pObject->BuildURL(pObject, pdest, loc);
  else
    Scaleform::GFx::URLBuilder::DefaultBuildURL(pdest, loc);
}
