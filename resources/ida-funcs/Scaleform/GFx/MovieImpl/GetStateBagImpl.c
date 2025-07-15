$6B4E7A01DD3034A6D235E05482AD75A2 *__thiscall Scaleform::GFx::MovieImpl::GetStateBagImpl(
        Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieDefRootNode *pPrev; // eax

  pPrev = this->RootMovieDefNodes.Root.pPrev;
  if ( pPrev )
    return &pPrev->4;
  else
    return 0;
}
