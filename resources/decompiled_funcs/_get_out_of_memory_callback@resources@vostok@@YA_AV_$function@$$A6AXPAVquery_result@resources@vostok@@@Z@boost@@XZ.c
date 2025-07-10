boost::function<void __cdecl(vostok::resources::query_result *)> *__usercall vostok::resources::get_out_of_memory_callback@<eax>(
        int a1@<eax>)
{
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)&s_out_of_memory_callback,
    a1);
  return (boost::function<void __cdecl(vostok::resources::query_result *)> *)a1;
}
