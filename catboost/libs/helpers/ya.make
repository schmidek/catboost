LIBRARY()



SRCS(
    array_subset.cpp
    borders_io.cpp
    checksum.cpp
    clear_array.cpp
    compare.cpp
    compression.cpp
    connected_components.cpp
    cpu_random.cpp
    dbg_output.cpp
    dense_hash.cpp
    dense_hash_view.cpp
    double_array_iterator.cpp
    dynamic_iterator.cpp
    element_range.cpp
    exception.cpp
    guid.cpp
    hash.cpp
    int_cast.cpp
    interrupt.cpp
    map_merge.cpp
    math_utils.cpp
    matrix.cpp
    maybe_data.cpp
    maybe_owning_array_holder.cpp
    mem_usage.cpp
    parallel_tasks.cpp
    power_hash.cpp
    progress_helper.cpp
    permutation.cpp
    query_info_helper.cpp
    resource_constrained_executor.cpp
    resource_holder.cpp
    restorable_rng.cpp
    serialization.cpp
    set.cpp
    sparse_array.cpp
    vec_list.cpp
    vector_helpers.cpp
    wx_test.cpp
    xml_output.cpp
)

PEERDIR(
    catboost/libs/data_types
    catboost/libs/data_util
    catboost/libs/index_range
    catboost/libs/logging
    library/binsaver
    library/containers/2d_array
    library/dbg_output
    library/digest/crc32c
    library/digest/md5
    library/malloc/api
    library/pop_count
    library/threading/local_executor
)

GENERATE_ENUM_SERIALIZATION(sparse_array.h)

END()

RECURSE(
    parallel_sort
    parallel_sort/ut
)
