unsigned __int8 __usercall vostok::render::read_srgb_flag@<al>(
        const unsigned __int8 *dds_ptr@<ecx>,
        unsigned int dds_size@<eax>)
{
  return dds_ptr[dds_size - 1];
}
