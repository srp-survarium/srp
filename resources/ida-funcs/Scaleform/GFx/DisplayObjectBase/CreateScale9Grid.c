void __thiscall Scaleform::GFx::DisplayObjectBase::CreateScale9Grid(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // esi
  float *v3; // eax
  Scaleform::Render::TreeNode *RenderNode; // eax
  const Scaleform::Render::State *State; // eax
  float *pData; // eax
  double v7; // st7
  double v8; // st7
  Scaleform::Render::Rect<float> *p_result; // eax
  double v10; // st7
  const Scaleform::Render::Matrix2x4<float> *v11; // eax
  Scaleform::Render::Rect<float> *(__thiscall *GetRectBounds)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // eax
  Scaleform::Render::Scale9GridInfo *v13; // edi
  Scaleform::Render::TreeNode *v14; // eax
  const Scaleform::Render::Matrix2x4<float> *v15; // eax
  int v16; // [esp+Ch] [ebp-64h] BYREF
  float x1; // [esp+10h] [ebp-60h]
  float y1; // [esp+14h] [ebp-5Ch]
  float x2; // [esp+18h] [ebp-58h]
  float y2; // [esp+1Ch] [ebp-54h]
  Scaleform::Render::Rect<float> result; // [esp+20h] [ebp-50h] BYREF
  float v22; // [esp+30h] [ebp-40h]
  float v23; // [esp+34h] [ebp-3Ch]
  float v24; // [esp+38h] [ebp-38h]
  float v25; // [esp+3Ch] [ebp-34h]
  Scaleform::Render::Rect<float> bounds; // [esp+40h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> shapeMtx; // [esp+50h] [ebp-20h] BYREF

  pParent = this->pParent;
  v3 = (float *)this->GetMatrix(this);
  shapeMtx.M[0][0] = *v3;
  shapeMtx.M[0][1] = v3[1];
  shapeMtx.M[0][2] = v3[2];
  shapeMtx.M[0][3] = v3[3];
  shapeMtx.M[1][0] = v3[4];
  shapeMtx.M[1][1] = v3[5];
  shapeMtx.M[1][2] = v3[6];
  shapeMtx.M[1][3] = v3[7];
  if ( pParent )
  {
    while ( 1 )
    {
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(pParent);
      State = Scaleform::Render::TreeNode::GetState(RenderNode, State_Log);
      if ( State )
      {
        pData = (float *)State->pData;
        v7 = pData[4];
        pData += 4;
        result.x1 = v7;
        result.y1 = pData[1];
        result.x2 = pData[2];
        v8 = pData[3];
        p_result = &result;
        result.y2 = v8;
        v10 = 0.0;
      }
      else
      {
        v10 = 0.0;
        p_result = &bounds;
        bounds.x1 = 0.0;
        bounds.y1 = 0.0;
        bounds.x2 = 0.0;
        bounds.y2 = 0.0;
      }
      x1 = p_result->x1;
      y1 = p_result->y1;
      x2 = p_result->x2;
      y2 = p_result->y2;
      if ( x2 > (double)x1 && y2 > (double)y1 )
        break;
      v11 = pParent->GetMatrix(pParent);
      Scaleform::Render::Matrix2x4<float>::Append(&shapeMtx, v11);
      pParent = pParent->pParent;
      if ( !pParent )
        return;
    }
    GetRectBounds = pParent->GetRectBounds;
    result.x1 = 1.0;
    v23 = 1.0;
    result.y1 = v10;
    result.x2 = v10;
    result.y2 = v10;
    v22 = v10;
    v24 = v10;
    v25 = v10;
    GetRectBounds(pParent, &bounds, (const Scaleform::Render::Matrix2x4<float> *)&result);
    v16 = 2;
    v13 = (Scaleform::Render::Scale9GridInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 448,
                                                 &v16);
    if ( v13 )
    {
      v14 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(pParent);
      Scaleform::Render::TreeNode::GetScale9Grid(v14, &result);
      v15 = pParent->GetMatrix(pParent);
      Scaleform::Render::Scale9GridInfo::Scale9GridInfo(v13, &result, v15, &shapeMtx, &bounds);
    }
  }
}
