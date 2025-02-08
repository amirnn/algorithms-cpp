//
// Created by Amir Nourinia on 08.02.25.
//

module;
#include <concepts>
#include <functional>
module List;
import ASort;

namespace datastructures {
    template<std::totally_ordered T>
    void ASortableList<T>::sort(std::function<algorithms::ASort<T>()> const &algorithm) {
        auto sortingAlgorithm = algorithm();
        sortingAlgorithm.sort(this);
    }
}


