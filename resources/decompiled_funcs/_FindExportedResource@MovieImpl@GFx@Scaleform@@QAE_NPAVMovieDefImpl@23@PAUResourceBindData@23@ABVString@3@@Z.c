char __thiscall Scaleform::GFx::MovieImpl::FindExportedResource(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDefImpl *localDef,
        Scaleform::GFx::ResourceBindData *presBindData,
        const Scaleform::String *symbol)
{
  Scaleform::GFx::MovieDefRootNode *pNext; // esi
  const Scaleform::GFx::MovieDefImpl *v7; // ebx
  Scaleform::List<Scaleform::GFx::MovieDefRootNode,Scaleform::GFx::MovieDefRootNode> *p_RootMovieDefNodes; // edi
  int v9; // eax
  Scaleform::GFx::MovieDefImpl *pDefImpl; // ecx

  if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(localDef, presBindData, symbol, 0) )
    return 1;
  pNext = this->RootMovieDefNodes.Root.pNext;
  v7 = localDef;
  p_RootMovieDefNodes = &this->RootMovieDefNodes;
  while ( 1 )
  {
    v9 = p_RootMovieDefNodes ? (int)&p_RootMovieDefNodes[-1].Root.4 : 0;
    if ( pNext == (Scaleform::GFx::MovieDefRootNode *)v9 )
      break;
    pDefImpl = pNext->pDefImpl;
    if ( pDefImpl != localDef && Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(pDefImpl, v7) )
    {
      if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(pNext->pDefImpl, presBindData, symbol, 0) )
        return 1;
      v7 = pNext->pDefImpl;
    }
    pNext = pNext->pNext;
  }
  return 0;
}
