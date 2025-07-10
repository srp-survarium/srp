bool __fastcall vostok::render::state_utils::operator==(
        const D3D11_SAMPLER_DESC *desc2,
        const D3D11_SAMPLER_DESC *desc1)
{
  return desc1->Filter == desc2->Filter
      && desc1->AddressU == desc2->AddressU
      && desc1->AddressV == desc2->AddressV
      && desc1->AddressW == desc2->AddressW
      && desc1->MipLODBias == desc2->MipLODBias
      && desc1->ComparisonFunc == desc2->ComparisonFunc
      && desc1->BorderColor[0] == desc2->BorderColor[0]
      && desc1->BorderColor[1] == desc2->BorderColor[1]
      && desc1->BorderColor[2] == desc2->BorderColor[2]
      && desc1->BorderColor[3] == desc2->BorderColor[3]
      && desc1->MinLOD == desc2->MinLOD
      && desc1->MaxLOD == desc2->MaxLOD;
}
