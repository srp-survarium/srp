char __thiscall Scaleform::Render::TreeNode::GetViewMatrix3D(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Matrix3x4<float> *mat)
{
  unsigned int State; // eax
  unsigned __int8 dst[48]; // [esp+10h] [ebp-30h] BYREF

  State = Scaleform::Render::StateBag::GetState(
            (Scaleform::Render::StateBag *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                      + 4
                                                      * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                       / 28)
                                                      + 20)
                                          + 64),
            State_FSCommandHandler);
  if ( !State )
    return 0;
  memcpy(dst, (unsigned __int8 *)(*(_DWORD *)(State + 4) + 16), sizeof(dst));
  memcpy((unsigned __int8 *)mat, dst, sizeof(Scaleform::Render::Matrix3x4<float>));
  return 1;
}
