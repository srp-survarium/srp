void __userpurge vostok::resources::query_resource_params::query_resource_params(
        vostok::resources::query_resource_params *this@<ecx>,
        const vostok::resources::request **a2@<edi>,
        const vostok::resources::query_resource_params *__that)
{
  const boost::function4<void,unsigned int,float,float,char const *> *v3; // [esp+0h] [ebp-8h]

  *a2 = __that->requests;
  a2[1] = (const vostok::resources::request *)__that->requests_create;
  a2[2] = (const vostok::resources::request *)__that->requests_count;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)&__that->callback,
    v3);
  a2[12] = (const vostok::resources::request *)__that->allocator;
  a2[13] = (const vostok::resources::request *)__that->target_satisfactions;
  a2[14] = (const vostok::resources::request *)__that->transforms;
  a2[15] = (const vostok::resources::request *)__that->user_data;
  a2[16] = (const vostok::resources::request *)__that->parent;
  a2[17] = (const vostok::resources::request *)__that->query_type;
  a2[18] = (const vostok::resources::request *)__that->request_mask;
  a2[19] = (const vostok::resources::request *)__that->flags;
  a2[20] = (const vostok::resources::request *)__that->quality_indexes;
  a2[21] = (const vostok::resources::request *)__that->disable_cache;
  a2[22] = (const vostok::resources::request *)__that->out_queries_id;
  a2[23] = (const vostok::resources::request *)__that->autoselect_quality;
  a2[24] = (const vostok::resources::request *)__that->assert_on_fail;
}
