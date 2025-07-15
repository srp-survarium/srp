void __usercall vostok::resources::query_resource_params::query_resource_params(
        vostok::resources::query_resource_params *this@<esi>,
        const vostok::resources::query_resource_params *__that@<edi>)
{
  this->requests = __that->requests;
  this->requests_create = __that->requests_create;
  this->requests_count = __that->requests_count;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&__that->callback,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->callback);
  this->allocator = __that->allocator;
  this->target_satisfactions = __that->target_satisfactions;
  this->transforms = __that->transforms;
  this->user_data = __that->user_data;
  this->parent = __that->parent;
  this->query_type = __that->query_type;
  this->request_mask = __that->request_mask;
  this->flags = __that->flags;
  this->quality_indexes = __that->quality_indexes;
  this->disable_cache = __that->disable_cache;
  this->out_queries_id = __that->out_queries_id;
  this->autoselect_quality = __that->autoselect_quality;
  this->assert_on_fail = __that->assert_on_fail;
}
