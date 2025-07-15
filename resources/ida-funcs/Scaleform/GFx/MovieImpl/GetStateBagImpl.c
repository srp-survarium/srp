$5EBB39F6624EA584C7A73E93BEC150A9 *__thiscall Scaleform::GFx::MovieImpl::GetStateBagImpl(
        Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieDefRootNode *pPrev; // eax

  pPrev = this->RootMovieDefNodes.Root.pPrev;
  if ( pPrev )
    return &pPrev->4;
  else
    return 0;
}
