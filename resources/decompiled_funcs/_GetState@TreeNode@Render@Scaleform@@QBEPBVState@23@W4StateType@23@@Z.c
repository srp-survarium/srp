const Scaleform::Render::State *__thiscall Scaleform::Render::TreeNode::GetState(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::StateType state)
{
  return (const Scaleform::Render::State *)Scaleform::Render::StateBag::GetState(
                                             (Scaleform::Render::StateBag *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                                                       + 4
                                                                                       * ((int)((int)&this[-1]
                                                                                              - ((unsigned int)this
                                                                                               & 0xFFFFF000))
                                                                                        / 28)
                                                                                       + 20)
                                                                           + 64),
                                             state);
}
