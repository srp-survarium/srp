void __thiscall Scaleform::GFx::AS3::MovieRoot::AddStickyVariable(
        Scaleform::GFx::AS3::MovieRoot *this,
        const Scaleform::GFx::ASString *path,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Value *val,
        Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::AS3::MovieRoot::StickyVarNode *v6; // eax
  Scaleform::GFx::MovieImpl::StickyVarNode *v7; // eax

  if ( name->pNode->Size )
  {
    v6 = (Scaleform::GFx::AS3::MovieRoot::StickyVarNode *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 32, 0);
    if ( v6 )
    {
      Scaleform::GFx::AS3::MovieRoot::StickyVarNode::StickyVarNode(v6, name, val, setType == SV_Permanent);
      if ( v7 )
        Scaleform::GFx::MovieImpl::AddStickyVariableNode(this->pMovieImpl, path, v7);
    }
  }
}
