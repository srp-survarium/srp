vostok::math::float4x4 *__userpurge boost::_mfi::cmf1<vostok::math::float4x4,transform_getter,void const *>::call<transform_getter * const,void const *>@<eax>(
        transform_getter **u@<eax>,
        const void **b1@<edx>,
        boost::_mfi::cmf1<vostok::math::float4x4,transform_getter,void const *> *this,
        void *__formal)
{
  _BYTE v5[64]; // [esp+10h] [ebp-40h] BYREF

  qmemcpy(__formal, (const void *)this->f_(*u, v5, *b1), 0x40u);
  return (vostok::math::float4x4 *)__formal;
}
