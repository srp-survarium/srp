void __stdcall Scaleform::GFx::GFx_DoActionLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::ASSupport *pObject; // ecx

  if ( (p->pLoadData.pObject->FileAttributes & 8) != 0 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "GFx_DoActionLoader - DoAction tag shouldn't appear in AS3 swf. Tag is skipped.");
  }
  else
  {
    pObject = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( pObject )
      pObject->DoActionLoader(pObject, p, tagInfo);
    else
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "GFx_DoActionLoader - AS2 support is not installed. Tag is skipped.");
  }
}
