void __stdcall Scaleform::GFx::GFx_DoInitActionLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::ASSupport *pObject; // ecx

  if ( (p->pLoadData.pObject->FileAttributes & 8) != 0 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "GFx_DoInitActionLoader - DoInitAction tag shouldn't appear in AS3 swf. Tag is skipped.");
  }
  else
  {
    pObject = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( pObject )
      pObject->DoInitActionLoader(pObject, p, tagInfo);
    else
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "GFx_DoInitActionLoader - AS2 support is not installed. Tag is skipped.");
  }
}
