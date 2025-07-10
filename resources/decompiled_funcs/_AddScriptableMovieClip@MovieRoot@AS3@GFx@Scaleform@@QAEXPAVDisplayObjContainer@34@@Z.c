void __thiscall Scaleform::GFx::AS3::MovieRoot::AddScriptableMovieClip(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::DisplayObjContainer *pspr)
{
  if ( !pspr->pParent )
  {
    Scaleform::GFx::InteractiveObject::AddToPlayList(pspr);
    Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(pspr);
  }
}
