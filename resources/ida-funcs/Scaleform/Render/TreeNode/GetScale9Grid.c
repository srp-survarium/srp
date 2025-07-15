Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::TreeNode::GetScale9Grid(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Rect<float> *result)
{
  unsigned int State; // eax
  float *v3; // eax
  double v4; // st7
  double v5; // st7
  Scaleform::Render::Rect<float> *v6; // eax
  Scaleform::Render::Rect<float> v7; // [esp+10h] [ebp-10h]

  State = Scaleform::Render::StateBag::GetState(
            (Scaleform::Render::StateBag *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                      + 4
                                                      * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                       / 28)
                                                      + 20)
                                          + 64),
            State_Log);
  if ( State )
  {
    v3 = *(float **)(State + 4);
    v4 = v3[4];
    v3 += 4;
    v7.x1 = v4;
    v7.y1 = v3[1];
    v7.x2 = v3[2];
    v5 = v3[3];
  }
  else
  {
    v5 = 0.0;
    v7.x1 = 0.0;
    v7.y1 = 0.0;
    v7.x2 = 0.0;
  }
  v6 = result;
  v7.y2 = v5;
  *result = v7;
  return v6;
}
