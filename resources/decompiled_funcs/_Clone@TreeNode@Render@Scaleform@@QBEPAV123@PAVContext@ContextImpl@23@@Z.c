Scaleform::Render::TreeNode *__thiscall Scaleform::Render::TreeNode::Clone(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  int v2; // esi
  Scaleform::Render::TreeNode *result; // eax
  Scaleform::Render::TreeNode *v4; // edi

  v2 = *(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                 + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                 + 20);
  result = (Scaleform::Render::TreeNode *)(*(int (__thiscall **)(int, Scaleform::Render::ContextImpl::Context *))(*(_DWORD *)v2 + 32))(
                                            v2,
                                            context);
  v4 = result;
  if ( result )
  {
    (*(void (__thiscall **)(int, Scaleform::Render::TreeNode *, Scaleform::Render::ContextImpl::Context *))(*(_DWORD *)v2 + 36))(
      v2,
      result,
      context);
    return v4;
  }
  return result;
}
