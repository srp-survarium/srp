unsigned int __usercall vostok::render::calc_mip_map_count@<eax>(unsigned int width@<eax>)
{
  return (__int64)(__FYL2X__((double)width, 0.6931471805599453094) / __FYL2X__(2.0, 0.6931471805599453094)) + 1;
}
