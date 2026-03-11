import numpy as np

def build_precision_recall_curve(true_labels: np.ndarray, predicted_probas: np.ndarray) -> np.ndarray:
    """
    Данная функция строит PR-кривую для задачи бинарной классификации.
    В случае, когда нет ни одного объекта положительного класса функция должна вызывать ValueError().

    Args:
        true_labels (np.ndarray): Массив истинных меток класса.
            Состоит из 0 и 1. 1 считается меткой положительного класса.
        predicted_probas (np.ndarray): Массив предсказанных вероятностей
            принадлежности объекта к положительному классу.

    Returns:
        np.ndarray: Массив размерами (len(true_labels)+1, 2),
            где в каждой строчке стоит пара (recall, precision),
            первым элементом всегда идет (0, 1)
    """
    if not np.any(true_labels):
        raise ValueError("Нет ни одного объекта положительного класса")
    
    sorted_indices = np.argsort(predicted_probas)[::-1]
    true_labels_sorted = true_labels[sorted_indices]
    
    cum_tp = np.cumsum(true_labels_sorted)
    cum_fp = np.cumsum(1 - true_labels_sorted)
    
    total_positives = np.sum(true_labels)
    
    precision = cum_tp / (cum_tp + cum_fp)
    recall = cum_tp / total_positives
    
    precision = np.concatenate([[1.0], precision])
    recall = np.concatenate([[0.0], recall])
    
    PR = np.column_stack((recall, precision))
    
    return PR