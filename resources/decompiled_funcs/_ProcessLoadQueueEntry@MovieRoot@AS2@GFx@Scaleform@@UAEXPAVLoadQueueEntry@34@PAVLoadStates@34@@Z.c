void __thiscall Scaleform::GFx::AS2::MovieRoot::ProcessLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::String pentry,
        Scaleform::GFx::LoadStates *pls)
{
  int v3; // edx

  v3 = *(_DWORD *)pentry.pData->Data;
  if ( (v3 & 4) != 0 )
  {
    Scaleform::GFx::AS2::MovieRoot::ProcessLoadVars(this, pentry, pls);
  }
  else if ( (v3 & 8) != 0 )
  {
    Scaleform::GFx::AS2::MovieRoot::ProcessLoadXML(this, pentry, pls);
  }
  else if ( (v3 & 0x10) != 0 )
  {
    Scaleform::GFx::AS2::MovieRoot::ProcessLoadCSS(this, pentry, pls);
  }
  else
  {
    Scaleform::GFx::AS2::MovieRoot::ProcessLoadMovieClip(this, (Scaleform::GFx::LoadQueueEntry *)pentry.pData, pls);
  }
}
