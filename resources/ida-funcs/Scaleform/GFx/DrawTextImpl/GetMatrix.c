Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::GFx::DrawTextImpl::GetMatrix(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Matrix2x4<float> *result)
{
  Scaleform::Render::Matrix2x4<float> *v2; // eax
  float *v3; // ecx

  v2 = result;
  v3 = (float *)(*(_DWORD *)(*(_DWORD *)(((int)this->pTextNode.pObject & 0xFFFFF000) + 0x10)
                           + 4
                           * ((int)((int)&this->pTextNode.pObject[-1] - ((int)this->pTextNode.pObject & 0xFFFFF000))
                            / 28)
                           + 20)
               + 16);
  result->M[0][0] = *v3;
  result->M[0][1] = v3[1];
  result->M[0][2] = v3[2];
  result->M[1][0] = v3[4];
  result->M[1][1] = v3[5];
  result->M[1][2] = v3[6];
  result->M[0][3] = v3[3] * 0.05000000074505806;
  result->M[1][3] = 0.05000000074505806 * v3[7];
  return v2;
}
