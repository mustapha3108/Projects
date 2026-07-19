# 📸 Pixabay Clone

A high-performance, full-stack image-sharing platform inspired by Pixabay. I built this project to push my web development skills beyond basic CRUD operations, focusing specifically on application speed, advanced search capabilities, and seamless client-server state management.

## 🚀 Overview

This platform allows users to discover, upload, and engage with high-quality imagery. By leveraging Laravel Octane, the application stays resident in memory, drastically reducing response times and handling concurrent requests efficiently. 

## ✨ Key Features

*   **Real-Time Search:** Integrated with **Meilisearch** to provide instant, highly relevant, and typo-tolerant image discovery as the user types.
*   **High-Speed Delivery:** Hosted and served via **Laravel Octane**, boosting overall application speed and backend performance.
*   **Interactive Social Engagement:** Users can seamlessly upload their own pictures, delete them, and leave comments or likes on others' work.
*   **UX-Aware Interactivity:** Designed with a focus on fluid state management between the server and client. Actions like liking or commenting update instantly on the UI without sacrificing backend synchronization or relying on heavy, bloated client-side logic.

## 🛠️ Tech Stack

*   **Backend:** Laravel + Laravel Octane
*   **Search Engine:** Meilisearch
*   **Frontend / State Management:** Alpine, Tailwind, Livewire
*   **Database:** SQlite

## 🧠 Architectural Highlights & Learning Outcomes

The primary goal of this project was mastering advanced web development concepts:
1.  **Memory Management:** Moving from a traditional request-lifecycle PHP app to a persistent Octane environment required careful management of memory leaks and state bleed between requests.
2.  **Optimized Search:** Offloading search queries from the primary database to Meilisearch improved latency and provided a much better user experience for media discovery.
3.  **Client-Server Sync:** Ensuring that rapid interactions (like spamming the "like" button) maintain accurate state without causing race conditions or UI jitter.

## 🚦 Getting Started

To run this project locally:

1. Clone the repository:
   ```
   git clone [https://github.com/](https://github.com/)[your-username]/[repo-name].git
