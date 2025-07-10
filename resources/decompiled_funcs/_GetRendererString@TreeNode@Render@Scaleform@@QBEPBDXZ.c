const char *__thiscall Scaleform::Render::TreeNode::GetRendererString(Scaleform::Render::TreeNode *this)
{
  unsigned int State; // eax

  State = Scaleform::Render::StateBag::GetState(
            (Scaleform::Render::StateBag *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                      + 4
                                                      * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                       / 28)
                                                      + 20)
                                          + 64),
            State_MultitouchInterface);
  if ( State )
    return (const char *)((*(_DWORD *)(*(_DWORD *)(State + 4) + 8) & 0xFFFFFFFC) + 8);
  else
    return 0;
}
