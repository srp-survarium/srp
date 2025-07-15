char __thiscall Scaleform::Render::TreeNode::GetProjectionMatrix3D(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Matrix4x4<float> *mat)
{
  unsigned int State; // eax
  __m128i dst[4]; // [esp+10h] [ebp-40h] BYREF

  State = Scaleform::Render::StateBag::GetState(
            (Scaleform::Render::StateBag *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                      + 4
                                                      * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                       / 28)
                                                      + 20)
                                          + 64),
            State_ExternalInterface);
  if ( !State )
    return 0;
  memcpy((int)dst, (const __m128i *)(*(_DWORD *)(State + 4) + 16), sizeof(dst));
  memcpy((int)mat, dst, sizeof(Scaleform::Render::Matrix4x4<float>));
  return 1;
}
