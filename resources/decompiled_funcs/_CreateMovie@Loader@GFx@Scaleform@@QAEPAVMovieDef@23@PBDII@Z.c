Scaleform::GFx::MovieDef *__thiscall Scaleform::GFx::Loader::CreateMovie(
        Scaleform::GFx::Loader *this,
        const char *pfilename,
        unsigned int loadConstants,
        unsigned int memoryArena)
{
  Scaleform::GFx::LoaderImpl *pImpl; // eax

  if ( pfilename && *pfilename && (pImpl = this->pImpl) != 0 )
    return Scaleform::GFx::LoaderImpl::CreateMovie(pImpl, pfilename, loadConstants | this->DefLoadFlags, memoryArena);
  else
    return 0;
}
